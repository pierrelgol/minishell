/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:31:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 18:31:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_vector	*vector_destroy(t_vector *vector)
{
	t_allocator *allocator;

	clib_assert(vector != NULL);
	allocator = vector->allocator;
	clib_assert(allocator != NULL);
	allocator->destroy(allocator, vector->data);
	allocator->destroy(allocator, vector);
	return (NULL);
}
