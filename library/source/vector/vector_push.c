/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:59:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:59:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	vector_push(t_vector *self, uintptr_t data)
{
	if (vector_is_full(self))
		vector_resize(self, self->size * 2);
	self->data[self->count++] = data;
}
