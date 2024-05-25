/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_should_grow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:11:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/20 10:11:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	buffer_should_grow(t_buffer *self, uint32_t requested)
{
	if (self->w + requested >= self->bsize)
		return (true);
	return (false);
}
