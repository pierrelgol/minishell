/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:46:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 10:46:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

bool	it_end(t_vector *self)
{
	return (self->index == self->count);
}

void	it_save(t_vector *self)
{
	self->saved = self->index;
}

void	it_restore(t_vector *self)
{
	self->index = self->saved;
}

void	it_advance(t_vector *self)
{
	if (it_end(self))
		return ;
	self->index += 1;
}
