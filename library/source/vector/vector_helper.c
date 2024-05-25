/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:53:57 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 19:53:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t vector_count(t_vector *vector)
{
	return (vector->count);
}

uint64_t vector_capacity(t_vector *vector)
{
	return (vector->capacity);
}

bool     vector_is_empty(t_vector *vector)
{
	return (vector->count == 0);
}

bool     vector_is_full(t_vector *vector)
{
	return (vector->count == vector->capacity);
}

bool     vector_end_of_vec(t_vector *vector, uint64_t index)
{
	return (index < vector->count);
}
