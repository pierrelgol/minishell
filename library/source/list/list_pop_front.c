/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:55:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:55:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	list_pop_front(t_list *self)
{
	uintptr_t	data;
	t_node		*node;

	node = list_remove_front(self);
	if (!node)
		return (0);
	data = node->data;
	node_destroy(node, self->allocator);
	return (data);
}
