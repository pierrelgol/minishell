/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:33:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 18:33:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool vector_resize(t_vector *vector, uint64_t new_capacity)
{
	t_allocator *allocator;
	uintptr_t   *new_data;

	clib_assert(vector != NULL);
	clib_assert(new_capacity != 0);
	allocator = vector->allocator;
	clib_assert(allocator != NULL);
	new_data = allocator->create(allocator, new_capacity * sizeof(uintptr_t));
	clib_assert(new_data != NULL);
	if (new_capacity < vector->capacity)
		memory_copy(new_data, vector->data, new_capacity * sizeof(uintptr_t));
	else
		memory_copy(new_data, vector->data, vector->count * sizeof(uintptr_t));
	allocator->destroy(allocator, vector->data);
	vector->data = new_data;
	vector->capacity = new_capacity;
	return (true);
}
