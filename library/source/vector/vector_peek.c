/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:58:57 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 18:58:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t vector_peek_front(t_vector *vector)
{
	if (vector_is_empty(vector))
		return (0);
	return (vector->data[0]);
}

uintptr_t vector_peek_back(t_vector *vector)
{
	if (vector_is_empty(vector))
		return (0);
	return (vector->data[vector->count - 1]);
}

uintptr_t vector_peek_at(t_vector *vector, uint64_t index)
{
	if (vector_is_empty(vector))
		return (0);
	clib_assert(index < vector->count);
	return (vector->data[index]);
}
