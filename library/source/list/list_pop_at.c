/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:57:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	list_pop_at(t_list *self, uint64_t index)
{
	uintptr_t	data;
	t_node		*node;

	node = list_remove_at(self, index);
	if (!node)
		return (0);
	data = node->data;
	node_destroy(node, self->allocator);
	return (data);
}
