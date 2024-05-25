/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:27:25 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:27:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"
#include <stdint.h>

uint64_t	buffer_reserve(t_buffer *self, uint64_t size)
{
	struct s_allocator	*allocator;
	char				*new_buffer;
	uint64_t			new_size;

	allocator = self->allocator;
	new_size = self->bsize + size;
	new_buffer = allocator->create(allocator, new_size + 1);
	memory_copy(new_buffer, self->buffer, self->bsize);
	allocator->destroy(allocator, self->buffer);
	self->buffer = new_buffer;
	self->bsize = new_size;
	return (new_size);
}
