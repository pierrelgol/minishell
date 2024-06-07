/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:18:58 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 13:19:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header/slib.h"

bool vector_insert_sorted(t_vector *self, uintptr_t elem, int64_t(cmp)(uintptr_t a, uintptr_t b))
{
	uint64_t pos;
	uint64_t i;

	if (self == NULL || self->data == NULL)
		return (false);
	pos = 0;
	if (self->is_sorted == 0)
		vector_sort(self, cmp);
	if (self->count == self->capacity)
	{
		if (!vector_resize(self, self->capacity * 2))
			return (false);
	}
	while (pos < self->count && cmp(self->data[pos], elem) < 0)
		pos++;
	i = self->count;
	while (i > pos)
	{
		self->data[i] = self->data[i - 1];
		i -= 1;
	}
	self->data[pos] = elem;
	self->count++;
	return true;
}
