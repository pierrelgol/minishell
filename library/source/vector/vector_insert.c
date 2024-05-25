/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:47:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 18:47:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool vector_insert_front(t_vector *vector, uintptr_t value)
{
	if (vector_is_full(vector))
	{
		if (!vector_resize(vector, vector->capacity * 2))
			return (false);
	}
	vector->count += 1;
	vector_expand(vector, 0);
	vector->data[0] = value;
	return (true);
}

bool vector_insert_back(t_vector *vector, uintptr_t value)
{
	if (vector_is_full(vector))
	{
		if (!vector_resize(vector, vector->capacity * 2))
			return (false);
	}
	vector->data[vector->count] = value;
	vector->count += 1;
	return (true);
}

bool vector_insert_at(t_vector *vector, uintptr_t value, uint64_t index)
{
	if (vector_is_full(vector))
	{
		if (!vector_resize(vector, vector->capacity * 2))
			return (false);
	}
	vector_expand(vector, index);
	vector->data[index] = value;
	vector->count += 1;
	return (true);
}
