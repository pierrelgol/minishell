/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:08:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 13:08:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

static void swap(uintptr_t *const a, uintptr_t *const b)
{
	const uintptr_t temp = *a;
	*a = *b;
	*b = temp;
}

static void quicksort(uintptr_t *data, int64_t left, int64_t right, int64_t(cmp)(uintptr_t a, uintptr_t b))
{
	int64_t pivot;
	int64_t i;
	int64_t j;

	if (left >= right)
		return;
	i = left;
	j = right;
	pivot = data[(left + right) / 2];
	while (i <= j)
	{
		while (cmp(data[i], pivot) < 0)
			i++;
		while (cmp(data[j], pivot) > 0)
			j--;
		if (i <= j)
		{
			swap(&data[i], &data[j]);
			i++;
			j--;
		}
	}
	quicksort(data, left, j, cmp);
	quicksort(data, i, right, cmp);
}

void vector_sort(t_vector *self, int64_t(cmp)(uintptr_t a, uintptr_t b))
{
	if (self == NULL || self->data == NULL || self->count < 2)
		return;
	quicksort(self->data, 0, self->count - 1, cmp);
	self->is_sorted = 1;
}
