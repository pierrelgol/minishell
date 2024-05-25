/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpa_reserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:31:39 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/16 09:20:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

static void gpa_insert_front(t_memory_node **head, t_memory_node *node)
{
	if (!*head)
	{
		*head = node;
		return;
	}
	else
	{
		node->next = (*head);
		(*head) = node;
	}
}

void gpa_reserve(t_allocator *self, uint64_t size, uint64_t count)
{
	t_memory_node *node;

	node = mem_node_create(size, count);
	gpa_insert_front(&self->freelist, node);
}
