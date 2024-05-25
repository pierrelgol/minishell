/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:57:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 13:57:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_node	*node_create(t_allocator *allocator, uintptr_t data)
{
	t_node	*node;

	node = allocator->create(allocator, sizeof(t_node));
	node->next = 0;
	node->data = data;
	return (node);
}
