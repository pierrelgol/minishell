/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpa_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:31:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/16 09:19:56 by pollivie         ###   ########.fr       */
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

void *gpa_create(t_allocator *self, uint64_t size)
{
	t_memory_node *node;
	void          *ptr;

	node = NULL;
	node = mem_node_remove_suitable(&self->freelist, size);
	if (node && self->logging)
		print(STDOUT_FILENO, "gpa_create(self, %lu) (reuse)\n", size);
	if (!node)
	{
		node = mem_node_create(size, 1);
		if (self->logging)
			print(STDOUT_FILENO, "gpa_create(self, %lu) (new)\n", size);
	}
	ptr = node->block;
	node->used = size;
	gpa_insert_front(&self->usedlist, node);
	return (ptr);
}
