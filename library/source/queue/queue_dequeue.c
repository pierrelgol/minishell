/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_dequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:47:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:47:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	queue_dequeue(t_queue *self)
{
	uintptr_t	data;
	t_node		*temp;

	if (queue_is_empty(self))
		return (0);
	data = self->head->head->data;
	temp = list_remove_front(self->head);
	temp->next = NULL;
	temp->data = 0;
	list_insert_front(self->freelist, temp);
	self->count--;
	return (data);
}
