/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_node_remove_suitable.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:56:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 13:56:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_memory_node	*mem_node_remove_suitable(t_memory_node **head, uint64_t size)
{
	t_memory_node	*prev;
	t_memory_node	*curr;

	if (!head || !*head || !size)
		return (0);
	if ((*head)->size >= size)
	{
		curr = (*head);
		(*head) = curr->next;
		curr->next = 0;
		return (curr);
	}
	prev = (*head);
	curr = (*head)->next;
	while (curr)
	{
		if (curr->size >= size)
			return (mem_node_remove_child(prev));
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}
