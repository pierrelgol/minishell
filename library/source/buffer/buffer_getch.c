/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_getch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:27:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:27:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

int32_t	buffer_getch(t_buffer *self)
{
	char	ch;

	if (self->r == self->w)
		return (0);
	ch = self->buffer[self->r++];
	self->ch = ch;
	buffer_compact(self);
	return ((int32_t)ch);
}
