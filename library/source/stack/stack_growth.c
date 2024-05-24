/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_growth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:26:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 14:26:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	stack_growth(t_stack *self)
{
	struct s_allocator	*allocator;
	t_node				*new_node;
	uint64_t			new_size;
	uint64_t			i;

	allocator = self->allocator;
	new_size = self->size * 2;
	i = self->size;
	while (i < new_size)
	{
		new_node = node_create(allocator, 0);
		list_insert_front(self->freelist, new_node);
		++i;
	}
	self->size = new_size;
}
