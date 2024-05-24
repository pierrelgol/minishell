/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:33:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:33:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_node	*list_remove_front(t_list *list)
{
	t_node	*node;

	node = NULL;
	if (list_is_empty(list))
		return (NULL);
	else if (list->size == 1)
	{
		node = list->head;
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		node = list->head;
		list->head = node_next(node);
		node->next = 0;
	}
	list->size -= 1;
	return (node);
}
