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

#ifndef BASE_ALLOCATOR_H
# define BASE_ALLOCATOR_H

# include <stddef.h>

# include "base_allocator_types.h"

extern const t_base_allocator	*g_default_base_allocator;

void							*ft_malloc(
									t_base_allocator *allocator,
									size_t size);

void							*ft_calloc(
									t_base_allocator *allocator,
									size_t item_count,
									size_t item_size);

void							*ft_realloc(
									t_base_allocator *allocator,
									void *ptr,
									size_t new_size);

void							*ft_free(
									t_base_allocator *allocator,
									void *ptr);

#endif
