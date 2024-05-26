/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:38:43 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 14:38:43 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_iterator *it_deinit(t_iterator *self)
{
	uintptr_t elem;

	if (self->dtor)
	{
		while (!it_end(self))
		{
			elem = it_peekcurr(self);
			self->dtor(self->allocator, elem);
		}
		
	}
	vector_clear(self->vec);
	self->index = 0;
	self->saved = 0;
	return (self);
}

bool it_save(t_iterator *self)
{
	if (vector_is_empty(self->vec))
		return (false);
	self->saved = self->index;
	return (true);
}

bool it_restore(t_iterator *self)
{
	if (vector_is_empty(self->vec))
		return (false);
	self->index = self->saved;
	return (true);
}

t_iterator *it_destroy(t_iterator *self)
{
	t_allocator *allocator;

	allocator = self->allocator;
	vector_destroy(self->vec);
	return  (NULL);
}
