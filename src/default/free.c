/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:20:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/02/20 21:40:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

#include "default_allocator.h"

void	ft_base_allocator_default_free(void *ptr)
{
	free((void *)((intptr_t)(ptr)
			- (intptr_t)(&((t_memory_block *) 0)->actual)));
}
