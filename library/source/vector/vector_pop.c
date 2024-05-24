/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:59:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:59:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	vector_pop(t_vector *self)
{
	uintptr_t	item;

	if (self->count == 0)
		return (0);
	self->count--;
	item = self->data[self->count];
	return (item);
}
