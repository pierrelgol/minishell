/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:59:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 11:59:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*heap_dup(t_allocator *self, void *ptr, uint64_t bytes)
{
	if (self->logging)
	{
		self->alloced += 1;
		self->size += bytes;
		print(STDOUT_FILENO, "heap_dup(self, %p, %lu)\n", ptr, bytes);
	}
	return (memory_dup(ptr, bytes));
}
