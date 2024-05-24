/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:29:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:29:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	buffer_read(t_buffer *self, char *buf, uint32_t size)
{
	uint64_t	unread_left;
	uint64_t	read_count;

	unread_left = buffer_unread_count(self);
	if (size >= unread_left)
		size = unread_left;
	read_count = string_copy_until_scalar(buf, self->buffer, 0x00, size);
	self->r += read_count;
	buffer_compact(self);
	return (read_count);
}
