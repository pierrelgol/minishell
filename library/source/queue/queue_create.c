/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:46:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:46:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_queue	*queue_create(struct s_allocator *allocator)
{
	t_queue	*queue;

	queue = (t_queue *)allocator->create(allocator, sizeof(t_queue));
	queue->allocator = allocator;
	queue->size = 1;
	queue->count = 0;
	queue->head = 0;
	queue->tail = 0;
	queue->freelist = list_create(allocator);
	return (queue);
}
