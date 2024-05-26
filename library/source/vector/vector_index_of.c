/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:45:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 13:47:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/clib.h"

int64_t vector_index_of(t_vector *vector, uint64_t offset, uintptr_t elem, bool (*eql)(uintptr_t e1, uintptr_t e2))
{
	uint64_t index;

	index = offset;
	while (index < vector->count)
	{
		if (eql(elem, vector->data[index]))
			return (index);
		++index;
	}
	return (-1);
}
