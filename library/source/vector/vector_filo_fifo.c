/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_filo_fifo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:42:43 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 19:42:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool vector_push(t_vector *vector, uintptr_t elem)
{
	clib_assert(vector != NULL);
	return (vector_insert_front(vector, elem));
}

bool vector_enqueue(t_vector *vector, uintptr_t elem)
{
	clib_assert(vector != NULL);
	return (vector_insert_back(vector, elem));
}

uintptr_t vector_dequeue(t_vector *vector)
{
	uintptr_t result;

	if (vector_is_empty(vector))
		return (0);
	clib_assert(vector != NULL);
	result = vector_peek_front(vector);
	vector_remove_front(vector);
	return (result);
}

uintptr_t vector_pop(t_vector *vector)
{
	uintptr_t result;

	if (vector_is_empty(vector))
		return (false);
	clib_assert(vector != NULL);
	result = vector_peek_back(vector);
	vector_remove_back(vector);
	return (result);
}
