/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:41:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:41:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_node	*list_remove_back(t_list *list)
{
	t_node	*new_tail;
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
		new_tail = node_get_nchild(list->head, list_size(list) - 1);
		node = node_remove_child(new_tail);
		list->tail = new_tail;
	}
	list->size -= 1;
	return (node);
}
