/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:21:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/14 14:21:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_list	*list_create(t_allocator *allocator)
{
	t_list	*list;

	list = allocator->create(allocator, sizeof(t_list));
	list->allocator = allocator;
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}
