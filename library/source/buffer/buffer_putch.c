/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_putch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:27:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:27:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

int32_t	buffer_putch(t_buffer *self, char ch)
{
	if (buffer_unwrite_count(self) == 0)
	{
		if (self->is_fixed)
			return (EOBUFF);
		else
			buffer_grow(self);
	}
	self->buffer[self->w++] = ch;
	return ((int32_t)ch);
}
