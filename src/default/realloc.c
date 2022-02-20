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

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#include <ft/memory.h>

#include "default_allocator.h"

void	*ft_base_allocator_default_realloc(void *ptr, size_t size)
{
	t_memory_block	*old;
	void			*result;

	old = (t_memory_block *)((intptr_t)(ptr)
			- (intptr_t)(&((t_memory_block *) 0)->actual));
	if (old->capacity < size)
	{
		result = ft_base_allocator_default_malloc(size);
		if (result)
			ft_memcpy(result, ptr, size);
		ft_base_allocator_default_free(old);
		return (result);
	}
	else
	{
		old->size = size;
		return (ptr);
	}
}
