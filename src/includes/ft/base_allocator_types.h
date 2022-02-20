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

#ifndef BASE_ALLOCATOR_TYPES_H
# define BASE_ALLOCATOR_TYPES_H

# include <stddef.h>

typedef struct s_base_allocator {
	void	*(*malloc)(size_t size);
	void	*(*realloc)(void *ptr, size_t size);
	void	(*free)(void *ptr);
}	t_base_allocator;

#endif
