/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:09:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 18:09:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_vector	*vector_create(t_allocator *allocator)
{
	t_vector	*vector;

	clib_assert(allocator != NULL);
	vector = allocator->create(allocator, sizeof(t_vector));
	clib_assert(vector != NULL);
	vector->allocator = allocator;
	vector->capacity = DEFAULT_VECTOR_CAPACITY;
	vector->count = 0;
	vector->data = allocator->create(allocator, vector->capacity * sizeof(uintptr_t));
	clib_assert(vector->data != NULL);
	return (vector);
}
