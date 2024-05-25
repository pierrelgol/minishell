/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_node_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:08:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 13:08:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_memory_node	*mem_node_create(uint64_t size, uint64_t count)
{
	t_memory_node	*node;

	node = memory_zalloc(sizeof(t_memory_node));
	node->block = memory_zalloc(size * count);
	node->size = size * count;
	node->used = 0;
	node->next = 0;
	return (node);
}
