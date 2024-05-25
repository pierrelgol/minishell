/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:29:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:29:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	buffer_write(t_buffer *self, char *buf, uint32_t size)
{
	uint64_t	write_space;
	uint64_t	written;

	write_space = buffer_unwrite_count(self);
	if (write_space < size)
	{
		if (!self->is_fixed)
			buffer_grow(self);
		else
			size = write_space;
	}
	written = string_copy_until_scalar(&self->buffer[self->w], buf, 0x00, size);
	self->w += written;
	return (written);
}
