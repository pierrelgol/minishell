/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:24:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 10:24:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

uintptr_t	vector_remove_front(t_vector *self)
{
	if (vector_is_empty(self))
		return (0);
	return (vector_remove_at(self, 0));
}

uintptr_t	vector_remove_back(t_vector *self)
{
	if (vector_is_empty(self))
		return (0);
	return (vector_remove_at(self, self->count - 1));
}

uintptr_t	vector_remove_after(t_vector *self, const uint64_t index)
{
	if (vector_is_empty(self))
		return (0);
	return (vector_remove_at(self, index + 1));
}

uintptr_t	vector_remove_at(t_vector *self, const uint64_t index)
{
	uint64_t	bytes_to_move;
	uintptr_t	elem;

	if (vector_is_empty(self) || index >= self->count)
		return (0);
	elem = self->data[index];
	bytes_to_move = (self->count - index - 1) * sizeof(uintptr_t);
	if (bytes_to_move)
		memory_move(self->data + index, self->data + index + 1, bytes_to_move);
	self->count -= 1;
	return (elem);
}
