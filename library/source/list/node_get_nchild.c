/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_get_nchild.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:03:52 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:03:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_node	*node_get_nchild(t_node *self, uint64_t n)
{
	t_node	*temp;

	if (!self || n == 0)
		return (self);
	temp = self;
	while (n--)
	{
		if (!node_next(temp))
			return (temp);
		temp = node_next(temp);
	}
	return (temp);
}
