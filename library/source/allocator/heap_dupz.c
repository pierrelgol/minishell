/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_dupz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:00:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 12:00:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*heap_dupz(t_allocator *self, void *ptr, uint64_t bytes)
{
	if (self->logging)
	{
		self->alloced += 1;
		self->size += bytes;
		print(STDOUT_FILENO, "heap_dupz(self, %p, %lu)\n", ptr, bytes);
	}
	return (memory_dupz(ptr, bytes));
}
