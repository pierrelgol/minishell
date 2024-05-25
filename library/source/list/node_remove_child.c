/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_remove_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:07:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:07:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_node	*node_remove_child(t_node *self)
{
	t_node	*child;

	if (!self || !node_next(self))
		return (NULL);
	child = node_next(self);
	self->next = node_next(child);
	child->next = 0;
	return (child);
}
