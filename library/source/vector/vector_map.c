/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:50:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 13:50:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void vector_map_dtor(t_vector *vector, t_allocator *allocator, uintptr_t (*dtor)(t_allocator *allocator, uintptr_t elem))
{
	uint64_t index;

	index = 0;
	while (index < vector->count)
	{
		vector->data[index] = dtor(allocator, vector->data[index]);
		++index;
	}
}
