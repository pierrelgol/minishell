/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_grow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:11:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/20 10:11:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	buffer_grow(t_buffer *self)
{
	struct s_allocator	*allocator;
	char				*new_buffer;
	uint64_t			new_size;

	allocator = self->allocator;
	new_size = self->bsize * 2;
	new_buffer = allocator->create(allocator, new_size + 1);
	memory_copy(new_buffer, self->buffer, self->bsize);
	allocator->destroy(allocator, self->buffer);
	self->buffer = new_buffer;
	self->bsize = (uint64_t)new_size;
	return (true);
}
