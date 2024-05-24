/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:00:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 09:00:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	vector_sort(t_vector *self, int (*f)(uintptr_t d1, uintptr_t d2))
{
	uint64_t	i;
	uint64_t	j;
	uintptr_t	tmp;

	i = 0;
	while (i < self->count)
	{
		j = i + 1;
		while (j < self->count)
		{
			if (f(self->data[i], self->data[j]) > 0)
			{
				tmp = self->data[i];
				self->data[i] = self->data[j];
				self->data[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
