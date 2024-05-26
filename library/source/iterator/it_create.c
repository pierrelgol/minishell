/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:12:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 14:12:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_iterator *it_create(t_allocator *allocator)
{
	t_iterator *self;

	self = allocator->create(allocator, sizeof(*self));
	if (!self)
		return (NULL);
	self->allocator = allocator;
	self->dtor = NULL;
	self->index = 0;
	self->vec = vector_create(allocator);
	return (self);
}

t_iterator *it_init_with_split(t_iterator *self, char **split)
{
	uint64_t i;

	i = 0;
	while (split[i])
	{
		vector_enqueue(self->vec, (uintptr_t) split[i]);
		++i;
	}
	return (self);
}

t_iterator *it_init_with_list(t_iterator *self, t_list *list)
{
	t_node *node;

	node = list->head;
	while (node)
	{
		vector_enqueue(self->vec, (uintptr_t) node->data);
		node = node->next;
	}
	return (self);
}

t_iterator *it_init_with_vector(t_iterator *self, t_vector *vector)
{
	vector_copy(self->vec, vector->data, vector->count);
	return (self);
}

t_iterator *it_set_dtor(t_iterator *self, t_dtor *dtor)
{
	self->dtor = dtor;
	return (self);
}
