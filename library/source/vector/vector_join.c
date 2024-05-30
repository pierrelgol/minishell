/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:40:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 20:40:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_vector *vector_join(t_allocator *allocator, t_vector *v1, t_vector *v2)
{
	t_vector *result;

	clib_assert(allocator != NULL);
	clib_assert(v1 != NULL);
	clib_assert(v2 != NULL);
	result = vector_create(allocator);
	clib_assert(result != NULL);
	result = vector_concat(result, v1);
	result = vector_concat(result, v2);
	return (result);
}
