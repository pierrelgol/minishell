/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:53:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:53:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	list_push_back(t_list *self, uintptr_t data)
{
	t_node	*node;

	node = node_create(self->allocator, data);
	list_insert_back(self, node);
}
