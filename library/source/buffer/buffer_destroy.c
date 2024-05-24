/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:23:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/19 21:23:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_buffer	*buffer_destroy(t_buffer *self)
{
	struct s_allocator	*allocator;

	allocator = self->allocator;
	allocator->destroy(allocator, self->buffer);
	allocator->destroy(allocator, self);
	return (0);
}
