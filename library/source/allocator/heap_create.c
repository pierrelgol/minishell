/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:52:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 11:52:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*heap_create(t_allocator *self, uint64_t size)
{
	void	*ptr;

	if (self->logging)
	{
		print(STDOUT_FILENO, "heap_create(self, %lu bytes)\n", size);
		self->alloced += 1;
		self->size += size;
	}
	ptr = memory_alloc(size);
	return (ptr);
}
