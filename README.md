# base_allocator

Allocators' common interface.

Don't use `malloc`, `free` directly, use allocator instead, to use custom allocator like `tcmalloc`, `jemalloc` easily

This library depends on `libft/memory` for initialize or move memory.

Caution: it's `g_base_default_allocator` is **NOT** compatible with `malloc` and `free`.

Note: goal of this project is providing base allocator, not custom heaps and/or middleware.

## Usage

To use it, you need to include its header.

```c
#include <ft/base_allocator.h>
```

Include *_\_types_.h instead if you don't want included size get too bigger and only need types not function prototypes (e.g. in header files for custom heap and/or middleware)

```c
#include <ft/base_allocator_types.h>
```

### Call `ft_`* functions (recommended)

You can use `calloc`'s functionality using `ft_calloc`, and more functions such as `ft_xalloc`, `ft_rcalloc`, `ft_memdup`, but with some more code.

```c
t_base_allocator    g_allocator = g_base_default_allocator;

// ...

T *new_array(T initial_value, size_t count)
{
    T   *result;
    int i;

    result = (T*)(ft_calloc(g_allocator, count, sizeof(T)));
    i = -1;
    if (result)
        while (++i < count)
            result[i] = initial_value;
    return (result);
}
```

### Call allocator's function directly

You can directly call allocator's function, but `malloc`, `realloc`, `free` is only supported.

```c
t_base_allocator    g_allocator = g_base_default_allocator;

// ...

T *new_array(T initial_value, size_t count)
{
    T   *result;
    int i;

    result = (T*)(g_allocator->malloc(count * sizeof(T)));
    i = -1;
    if (result)
        while (++i < count)
            result[i] = initial_value;
    return (result);
}
```

## Contributing

Any PR is welcome if below kept

- _**[DON'T COMMIT FILES WITH 42 HEADER NOT REMOVED](#remove-42-header)**_
- If possible, keep the [Norm](https://github.com/42School/norminette)

### pre-commit hook

Run `init.sh` to initialize git pre-commit hook.

```sh
bash init.sh
```

Note: POSIX shell is not supported. use bash instead.

It will copy `hooks/pre-commit.sh` into `.git/hooks/pre-commit`, and set execute permission on it.

#### remove 42 header

File history managed by VCS.

Just let VCS handle it, and stop polluting history :)

This pre-commit script will remove 42 header from `Makefile` and `*.{c,h,sh,mk}` files

Alternative: run shell command below **before every commit**, or never touch 42 header

```sh
find . -name '*.c' -o -name "*.h" -o -name "*.sh" -o -name "*.mk" -o -name "Makefile" \
| xargs -L1 sh hooks/scripts/42header-remover.sh
```

### dependencies

It will automatically download Github release assets for dependencies described in the `ft_header_deps.properties` file.

After change dependencies, please run `build/script/init-header-deps.sh` manually.
