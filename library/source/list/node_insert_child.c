/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_insert_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:06:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:06:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	node_insert_child(t_node *self, t_node *child)
{
	if (!self || !child)
		return ;
	child->next = node_next(self);
	self->next = node_next(child);
}
