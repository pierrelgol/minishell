/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_compact.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:19:13 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/20 08:19:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	buffer_compact(t_buffer *self)
{
	uint64_t	bytes_remaining;

	if (self->r > self->w)
		bytes_remaining = 0;
	else
		bytes_remaining = self->w - self->r;
	if (bytes_remaining > 0)
	{
		memory_move(self->buffer, self->buffer + self->r, bytes_remaining);
		self->r = 0;
		self->w = bytes_remaining;
	}
	else
	{
		self->r = 0;
		self->w = 0;
	}
}
