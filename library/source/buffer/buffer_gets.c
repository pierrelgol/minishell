/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_gets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:27:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:27:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"
#include <stdio.h>

char	*buffer_gets(t_buffer *self, char *dest, uint32_t dsize)
{
	uint64_t	unread_count;
	uint64_t	written;

	unread_count = buffer_unread_count(self);
	if (unread_count < dsize)
		dsize = unread_count;
	written = string_copy_until_scalar(dest, self->buffer, '\n', dsize);
	self->r += written + 1;
	buffer_compact(self);
	return (dest);
}
