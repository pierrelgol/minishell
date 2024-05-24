/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:00:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 09:00:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	vector_resize(t_vector *self, uint64_t new_size)
{
	struct s_allocator	*allocator;
	uintptr_t			*new_data;

	allocator = self->allocator;
	if (new_size < self->size)
		return ;
	new_data = allocator->create(allocator, new_size * sizeof(uintptr_t) + 1);
	memory_copy(new_data, self->data, self->size * sizeof(uintptr_t));
	allocator->destroy(self->allocator, self->data);
	self->data = new_data;
	self->size = new_size;
}
