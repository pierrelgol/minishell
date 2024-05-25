/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:25:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 15:25:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_list	*list_destroy(t_list *self)
{
	t_allocator	*allocator;
	t_node		*node;

	if (!self)
		return (0);
	allocator = self->allocator;
	while (!list_is_empty(self))
	{
		node = list_remove_front(self);
		node_destroy(node, allocator);
	}
	allocator->destroy(allocator, self);
	return (0);
}
