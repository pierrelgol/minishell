/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:00:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 09:00:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	vector_remove_at(t_vector *self, uint64_t index)
{
	uintptr_t	*data;
	uintptr_t	value;

	if (index >= self->count || self->count == 0)
		return (0);
	data = self->data;
	value = data[index];
	if (index < self->count - 1)
        memory_move(&data[index], &data[index + 1], (self->count - index - 1) * sizeof(uintptr_t));
	self->count--;
	return (value);
}
