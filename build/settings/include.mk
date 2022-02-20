# common Makefile to include - entrypoint

ifndef BASE_DIR
$(error variable BASE_DIR (where src exists) is not set)
endif

include $(BASE_DIR)/build/settings/functions.mk
include $(BASE_DIR)/build/settings/variables.mk

$(call require_v, NAME, target name)
$(call require_v, TARGET_MODE, debug or release)
$(call require_v, TARGET_TYPE, a or so)

# common variables
CC = gcc
SRC_DIR := $(BASE_DIR)/src
CFLAGS := -Weverything -Wno-poison-system-directories -Werror -std=c99 -pedantic -I$(SRC_DIR)/includes -I$(BASE_DIR)/.ft_cache/dependencies/includes
LDFLAGS := -L$(BASE_DIR)/.ft_cache/dependencies $(shell sh $(BASE_DIR)/build/scripts/get-dependencies.sh $(BASE_DIR))
SRCS := $(shell sh $(BASE_DIR)/build/scripts/get-srcs.sh $(SRC_DIR))
OBJS := $(SRCS:%.c=%.o)

# util variables
Q = $(if $(filter 1,$(V) $(VERBOSE)),,@)

# mode specific additional flags
include $(BASE_DIR)/build/settings/mode.mk

# rule for target
include $(BASE_DIR)/build/settings/target.mk

# common .PHONY rules
all: $(TARGET)
clean:
	$(Q)$(shell sh $(BASE_DIR)/build/scripts/clean.sh)
fclean: clean
	$(Q)rm -rf $(TARGET)
re: fclean all
.PHONY: all clean fclean re

# common rules
define build_common_rule
$1: $2
	$(Q)mkdir -p $(dir $1)
	$(Q)$(CC) $(CFLAGS) -c $2 -o $1 -MD
endef
$(foreach f, \
	$(OBJS), \
	$(eval $(call \
		build_common_rule, \
		$f, \
		$(shell sh $(BASE_DIR)/build/scripts/o-to-src.sh $f $(SRC_DIR)) \
	)) \
)

# auto updated dependencies
-include $(OBJS:%.o=%.d)
