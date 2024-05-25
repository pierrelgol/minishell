/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:49:39 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:49:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	stack_pop(t_stack *self)
{
	t_node		*node;
	uintptr_t	data;

	if (stack_is_empty(self))
		return (0);
	self->count--;
	node = list_remove_front(self->top);
	data = node->data;
	node->data = 0;
	node->next = 0;
	list_insert_front(self->freelist, node);
	return (data);
}
