/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_compact.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:38:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 18:38:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_vector *vector_compact(t_vector *vector, uint64_t from)
{	
	uint64_t bytes_to_move;

	clib_assert(from < vector->count);
	bytes_to_move = (vector->count - from * sizeof(uintptr_t));
	vector->data = memory_move(&vector->data[from], &vector->data[from + 1], bytes_to_move);		
	return (vector);
}
