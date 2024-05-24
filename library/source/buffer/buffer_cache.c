/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_cache.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:53:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/20 11:53:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	buffer_cache(t_buffer *self, int32_t fd)
{
	char		*buffer;
	uint64_t	rsize;

	buffer = (char [PAGE_SIZE]){0};
	buffer_reserve(self, PAGE_SIZE);
	rsize = (uint64_t)read(fd, &buffer[self->w], PAGE_SIZE - 1);
	self->w += rsize;
	return (rsize);
}
