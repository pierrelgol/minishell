/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_peekcurr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:30:01 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 14:30:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t it_peekcurr(t_iterator *self)
{
	if (it_end(self))
		return (0);
	return (vector_peek_at(self->vec, self->index));
}

uintptr_t it_peeknext(t_iterator *self)
{
	if (it_end(self) || self->index + 1 >= self->vec->count)
		return (0);
	return (vector_peek_at(self->vec, self->index + 1));
}

uintptr_t it_peekprev(t_iterator *self)
{
	if (vector_is_empty(self->vec) || self->index < 1)
		return (0);
	return (vector_peek_at(self->vec, self->index - 1));
}
