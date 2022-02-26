/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/base_allocator.h>

#include "default_allocator.h"

static const t_base_allocator	g_default = {
	&ft_base_allocator_default_malloc,
	&ft_base_allocator_default_realloc,
	&ft_base_allocator_default_free,
};

const t_base_allocator			*g_default_base_allocator = &g_default;
