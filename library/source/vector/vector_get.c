/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:14:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 19:14:24 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t *vector_get_front(t_vector *vector)
{
	clib_assert(vector != NULL);
	if (vector_is_empty(vector))
		return (NULL);
	return (&vector->data[0]);
}

uintptr_t *vector_get_back(t_vector *vector)
{
	clib_assert(vector != NULL);
	if (vector_is_empty(vector))
		return (NULL);
	return (&vector->data[vector->count - 1]);
}

uintptr_t *vector_get_at(t_vector *vector, uint64_t index)
{
	clib_assert(vector != NULL);
	if (vector_is_empty(vector))
		return (NULL);
	clib_assert(index < vector->count);
	return (&vector->data[index]);
}
