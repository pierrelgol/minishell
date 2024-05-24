/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:00:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 09:00:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	vector_insert_at(t_vector *self, uintptr_t data, uint64_t index)
{
	uintptr_t	*new_data;
	uint64_t	i;

	if (index > self->count)
		index = self->count;
	if (self->count == self->size)
		vector_resize(self, self->size * 2);
	new_data = self->data;
	i = self->count;
	while (i > index)
	{
		new_data[i] = new_data[i - 1];
		i--;
	}
	new_data[index] = data;
	self->count++;
	return (data);
}
