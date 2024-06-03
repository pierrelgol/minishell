/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:05:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 11:05:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

bool	vector_resize(t_vector *self, const uint64_t new_capacity)
{
	uintptr_t	*old_data;
	uint64_t	old_capacity;

	old_capacity = self->count;
	old_data = self->data;
	self->data = (uintptr_t *)memory_alloc(new_capacity * sizeof(uintptr_t));
	if (!self->data)
	{
		self->data = old_data;
		return (false);
	}
	memory_copy(self->data, old_data, old_capacity * sizeof(uintptr_t));
	self->capacity = new_capacity;
	memory_dealloc(old_data);
	return (true);
}
