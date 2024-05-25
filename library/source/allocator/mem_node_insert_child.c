/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_node_insert_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:25:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 13:25:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	mem_node_insert_child(t_memory_node *self, t_memory_node *child)
{
	if (!self || !child)
		return ;
	child->next = self->next;
	self->next = child;
}
