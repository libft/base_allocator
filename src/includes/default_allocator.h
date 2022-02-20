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

#ifndef DEFAULT_ALLOCATOR_H
# define DEFAULT_ALLOCATOR_H

# include <stddef.h>

typedef struct s_memory_block {
	size_t	capacity;
	size_t	size;
	char	actual[];
}	t_memory_block;

void	*ft_base_allocator_default_malloc(size_t size);
void	*ft_base_allocator_default_realloc(void *ptr, size_t size);
void	ft_base_allocator_default_free(void *ptr);

#endif
