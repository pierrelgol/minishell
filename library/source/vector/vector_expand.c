/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:43:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 18:43:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"
#include <string.h>

t_vector *vector_expand(t_vector *vector, uint64_t at)
{
	uint64_t bytes_to_move;

	clib_assert(at <= vector->count);
	bytes_to_move = (vector->count - at) * sizeof(uintptr_t);
	memory_move(&vector->data[at + 1], &vector->data[at], bytes_to_move);
	return (vector);
}
