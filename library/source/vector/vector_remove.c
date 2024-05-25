/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:51:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 18:51:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool vector_remove_front(t_vector *vector)
{
	clib_assert(vector != NULL);
	if (vector_is_empty(vector))
		return (false);
	vector->data[0] = 0;
	vector_compact(vector, 0);
	vector->count -= 1;
	return (true);
}

bool vector_remove_back(t_vector *vector)
{
	clib_assert(vector != NULL);
	if (vector_is_empty(vector))
		return (false);
	vector->data[vector->count - 1] = 0;
	vector->count -= 1;
	return (true);
}

bool vector_remove_at(t_vector *vector, uintptr_t index)
{
	clib_assert(vector != NULL);
	if (vector_is_empty(vector))
		return (false);
	clib_assert(index < vector->count);
	vector->data[index] = 0;
	vector_compact(vector, index);
	vector->count -= 1;
	return (true);
}
