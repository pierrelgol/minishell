/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_deinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:50:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 11:50:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*heap_deinit(t_allocator *self)
{
	if (self->logging)
	{
		print(STDOUT_FILENO, "heap_create was called  : %lu times\n",
			self->alloced);
		print(STDOUT_FILENO, "heap_destroy was called : %lu times\n",
			self->dealloced);
		print(STDOUT_FILENO, "total allocation        : %lu bytes\n",
			self->size);
	}
	memory_dealloc(self);
	return (0);
}
