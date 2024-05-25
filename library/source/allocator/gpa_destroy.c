/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpa_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:31:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/16 09:20:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

static void gpa_insert_front(t_memory_node **head, t_memory_node *node)
{
	if (!*head)
	{
		*head = node;
		node->next = NULL;
		return;
	}
	else
	{
		node->next = (*head);
		(*head) = node;
	}
}

void *gpa_destroy(t_allocator *self, void *ptr)
{
	t_memory_node *node;

	node = mem_node_remove_matching(&self->usedlist, (uintptr_t) ptr);
	if (node && self->logging)
		print(STDOUT_FILENO, "gc_destroy(self, %p)(found)\n", ptr);
	if (!node)
	{
		if (self->logging)
			print(STDOUT_FILENO, "gc_destroy(self, %p)(leaked)\n", ptr);
		return (0);
	}
	memory_set(node->block, 0x00, node->size);
	node->used = 0;
	gpa_insert_front(&self->freelist, node);
	return (0);
}
