/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:28:52 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 19:28:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool vector_copy_from(t_vector *vector, uint64_t offset, uintptr_t *src, uint64_t srcsize)
{
	uint64_t	i;

	clib_assert(vector != NULL);
	clib_assert(src != NULL);
	clib_assert(offset + vector->count < vector->capacity);
	i = 0;
	while (i < srcsize)
	{
		if (vector_insert_at(vector, src[i], i + offset))
			return (false);
		++i;
	}
	return (true);
}

bool vector_copy(t_vector *vector, uintptr_t *src, uint64_t srcsize)
{
	return (vector_copy_from(vector, 0, src, srcsize));
}
