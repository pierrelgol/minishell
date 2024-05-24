/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_enqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:47:39 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:47:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	queue_enqueue(t_queue *self, uintptr_t data)
{
	t_node	*node;

	if (queue_is_full(self))
		queue_growth(self);
	node = list_remove_front(self->freelist);
	node->data = data;
	node->next = NULL;
	list_insert_back(self->head, node);
	self->count++;
}
