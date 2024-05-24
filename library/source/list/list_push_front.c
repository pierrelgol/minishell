/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:47:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:47:13 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	list_push_front(t_list *self, uintptr_t data)
{
	t_node	*node;

	node = node_create(self->allocator, data);
	list_insert_front(self, node);
}
