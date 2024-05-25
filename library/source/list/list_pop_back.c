/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:57:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:57:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	list_pop_back(t_list *self)
{
	uintptr_t	data;
	t_node		*node;

	node = list_remove_back(self);
	if (!node)
		return (0);
	data = node->data;
	node_destroy(node, self->allocator);
	return (data);
}
