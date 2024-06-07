/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:12:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 13:12:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

static int64_t binary_search(t_vector *self, uintptr_t elem, int64_t(cmp)(uintptr_t a, uintptr_t b))
{
	int64_t left = 0;
	int64_t mid = 0;
	int64_t right = self->count - 1;
	int64_t comparison;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		comparison = cmp(self->data[mid], elem);
		if (comparison == 0)
			return (mid);
		else if (comparison < 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

static int64_t linear_search(t_vector *self, uintptr_t elem, int64_t(cmp)(uintptr_t a, uintptr_t b))
{
	uint64_t i;

	i = 0;
	while (i < self->count)
	{
		if (cmp(self->data[i], elem) == 0)
			return (i);
		i += 1;
	}
	return (-1);
}

int64_t vector_search(t_vector *self, uintptr_t elem, int64_t(cmp)(uintptr_t a, uintptr_t b))
{
	if (self == NULL || self->data == NULL)
		return -1;

	if (self->is_sorted)
		return (binary_search(self, elem, cmp));
	else
		return (linear_search(self, elem, cmp));

	return -1;
}
