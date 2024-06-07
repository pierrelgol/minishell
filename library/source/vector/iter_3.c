/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:54:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 10:54:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

uintptr_t	it_peek_next(t_vector *self)
{
	if (self->index + 1 >= self->count)
		return (0);
	return (*(self->data + self->index + 1));
}

uintptr_t	it_peek_curr(t_vector *self)
{
	if (self->index >= self->count)
		return (0);
	return (*(self->data + self->index));
}

uintptr_t	it_peek_prev(t_vector *self)
{
	if (self->index < 1 || self->count == 0)
		return (0);
	return (*(self->data + self->index - 1));
}
