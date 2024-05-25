/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:23:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:23:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_buffer	*buffer_create(struct s_allocator *allocator, uint32_t size,
		bool is_fixed)
{
	t_buffer	*self;

	self = allocator->create(allocator, 1 * sizeof(t_buffer));
	self->allocator = allocator;
	if (size < PAGE_SIZE)
		size = PAGE_SIZE;
	self->buffer = allocator->create(allocator, size);
	self->is_fixed = is_fixed;
	self->ch = 0;
	self->bsize = size;
	self->r = 0;
	self->w = 0;
	return (self);
}
