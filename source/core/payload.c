/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   payload.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_token_payload *token_payload_create(t_allocator *allocator)
{
	t_token_payload *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	return (self);
}

void token_payload_init(t_allocator *allocator, t_token_payload *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
}
void token_payload_deinit(t_allocator *allocator, t_token_payload *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
}

t_token_payload *token_payload_destroy(t_allocator *allocator, t_token_payload *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	allocator->destroy(allocator, self);
	return (NULL);
}
