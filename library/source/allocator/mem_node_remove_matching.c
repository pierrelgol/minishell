/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_node_remove_matching.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:30:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 13:30:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	mem_node_address_is_in_range(t_memory_node *node, uintptr_t address)
{
	uintptr_t	sp;
	uintptr_t	ep;

	if (!node)
		return (false);
	sp = (uintptr_t)node->block;
	ep = (uintptr_t)node->block + node->size;
	return (address >= sp && address <= ep);
}

t_memory_node	*mem_node_remove_matching(t_memory_node **head,
		uintptr_t address)
{
	t_memory_node	*prev;
	t_memory_node	*curr;

	if (!head || !*head || !address)
		return (0);
	if (mem_node_address_is_in_range(*head, address))
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
		if (mem_node_address_is_in_range(curr, address))
			return (mem_node_remove_child(prev));
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}
