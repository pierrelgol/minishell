/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:10:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/20 10:10:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	buffer_clear(t_buffer *self)
{
	memory_set(self->buffer, 0x00, self->bsize);
	self->r = 0;
	self->w = 0;
	return (self);
}
