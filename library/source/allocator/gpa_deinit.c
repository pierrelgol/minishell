/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpa_deinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:31:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/16 09:20:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

static t_memory_node *gpa_remove_front(t_memory_node **head)
{
	t_memory_node *node;

	node = NULL;
	if (!*head)
		return (NULL);
	node = (*head);
	(*head) = node->next;
	return (node);
}

void *gpa_deinit(t_allocator *gpa)
{
	t_memory_node *node;

	node = NULL;
	node = gpa_remove_front(&gpa->usedlist);
	while (node)
	{
		mem_node_destroy(node);
		node = gpa_remove_front(&gpa->usedlist);
	}
	node = NULL;
	node = gpa_remove_front(&gpa->freelist);
	while (node)
	{
		mem_node_destroy(node);
		node = gpa_remove_front(&gpa->freelist);
	}
	memory_dealloc(gpa);
	return (0);
}
