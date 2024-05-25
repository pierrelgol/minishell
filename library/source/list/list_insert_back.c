/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:26:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:26:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	list_insert_back(t_list *self, t_node *new_tail)
{
	if (list_is_empty(self))
	{
		self->head = new_tail;
		self->tail = new_tail;
	}
	else if (self->size == 1)
	{
		self->head->next = new_tail;
		self->tail = new_tail;
	}
	else
	{
		self->tail->next = new_tail;
		self->tail = new_tail;
	}
	self->size += 1;
}
