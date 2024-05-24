/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_node_count_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:27:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 13:27:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	mem_node_count_child(t_memory_node *self)
{
	t_memory_node	*child;
	uint64_t		count;

	if (!self || !self->next)
		return (0);
	count = 0;
	child = self;
	while (child)
	{
		child = child->next;
		++count;
	}
	return (count);
}
