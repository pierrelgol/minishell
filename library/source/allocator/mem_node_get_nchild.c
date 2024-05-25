/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_node_get_nchild.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:23:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 13:23:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_memory_node	*mem_node_get_nchild(t_memory_node *self, uint64_t n)
{
	t_memory_node	*temp;

	if (!self || n == 0)
		return (self);
	temp = self;
	while (n--)
	{
		if (!mem_node_next(temp))
			return (temp);
		temp = mem_node_next(temp);
	}
	return (temp);
}
