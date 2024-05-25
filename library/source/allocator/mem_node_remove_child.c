/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_node_remove_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:25:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 13:26:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_memory_node	*mem_node_remove_child(t_memory_node *self)
{
	t_memory_node	*child;

	if (!self || !self->next)
		return (0);
	child = self->next;
	self->next = child->next;
	child->next = 0;
	return (child);
}
