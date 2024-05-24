/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_unread_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:27:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/20 08:27:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	buffer_unread_count(t_buffer *self)
{
	if (self->r > self->w)
		return (0);
	return (self->w - self->r);
}
