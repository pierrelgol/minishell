/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:45:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 09:45:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

t_vector *vector_create(void)
{
	t_vector *self;

	self = (t_vector *) memory_alloc(sizeof(t_vector));
	if (!self)
		return (NULL);
	self->capacity = VECTOR_DEFAULT_CAPACITY;
	self->count = 0;
	self->is_sorted = false;
	self->data = memory_alloc(VECTOR_DEFAULT_CAPACITY * sizeof(uintptr_t));
	if (!self->data)
		return (vector_destroy(self));
	return (self);
}

t_vector *vector_create_with_capacity(const uint64_t capacity)
{
	t_vector *self;

	self = (t_vector *) memory_alloc(sizeof(t_vector));
	if (!self)
		return (NULL);
	self->capacity = capacity;
	self->count = 0;
	self->data = memory_alloc(capacity * sizeof(uintptr_t));
	if (!self->data)
		return (vector_destroy(self));
	return (self);
}
