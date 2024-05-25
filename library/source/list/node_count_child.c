/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_count_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:10:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:10:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	node_count_child(t_node *self)
{
	uint64_t	count;
	t_node		*child;

	if (!self || !node_next(self))
		return (0);
	count = 0;
	child = self;
	while (child)
	{
		child = node_next(child);
		++count;
	}
	return (count);
}
