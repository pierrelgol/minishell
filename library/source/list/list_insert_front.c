/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:24:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:24:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	list_insert_front(t_list *self, t_node *new_head)
{
	if (list_is_empty(self))
	{
		self->head = new_head;
		self->tail = new_head;
	}
	else if (self->size == 1)
	{
		self->head = new_head;
		new_head->next = self->tail;
	}
	else
	{
		new_head->next = self->head;
		self->head = new_head;
	}
	self->size += 1;
}
