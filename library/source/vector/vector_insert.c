/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:15:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 10:15:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

bool	vector_insert_front(t_vector *self, uintptr_t elem)
{
	return (vector_insert_at(self, elem, 0));
}

bool	vector_insert_back(t_vector *self, uintptr_t elem)
{
	return (vector_insert_at(self, elem, self->count));
}

bool	vector_insert_after(t_vector *self, uintptr_t elem,
		const uint64_t index)
{
	return (vector_insert_at(self, elem, index + 1));
}

bool	vector_insert_at(t_vector *self, uintptr_t elem, const uint64_t index)
{
	uint64_t	bytes_to_move;

	if (index > self->count)
		return (false);
	if (vector_is_full(self))
	{
		if (!vector_resize(self, self->capacity * 2))
			return (false);
	}
	bytes_to_move = (self->count - index) * sizeof(uintptr_t);
	memory_move((self->data + index + 1), (self->data + index), bytes_to_move);
	self->data[index] = elem;
	self->count += 1;
	return (true);
}
