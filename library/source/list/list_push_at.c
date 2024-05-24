/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:54:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:54:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	list_push_at(t_list *self, uintptr_t data, uint64_t index)
{
	t_node	*node;

	node = node_create(self->allocator, data);
	list_insert_at(self, node, index);
}
