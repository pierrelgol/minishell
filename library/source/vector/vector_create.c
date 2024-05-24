/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:58:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:58:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_vector	*vector_create(struct s_allocator *allocator, uint64_t size)
{
	t_vector	*vector;

	vector = allocator->create(allocator, sizeof(t_vector));
	vector->allocator = allocator;
	vector->size = size;
	vector->count = 0;
	vector->data = allocator->create(allocator, sizeof(uintptr_t) * size + 1);
	return (vector);
}
