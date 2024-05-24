/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_puts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:27:25 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:27:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*buffer_puts(t_buffer *self, char *str)
{
	uint64_t	written;
	char		*ptr;

	ptr = &self->buffer[self->w];
	written = string_copy_until_scalar(&self->buffer[self->w], str, '\n',
			buffer_unwrite_count(self));
	self->w += written + 1;
	return (ptr);
}
