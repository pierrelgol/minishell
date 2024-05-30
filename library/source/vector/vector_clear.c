/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:43:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 20:43:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_vector	*vector_clear(t_vector *vector)
{
	uint64_t	total_byte_count;

	clib_assert(vector != NULL);
	total_byte_count = vector->count * sizeof(uintptr_t);
	memory_set(vector->data, 0x00, total_byte_count);
	vector->count = 0;
	return (vector);
}
