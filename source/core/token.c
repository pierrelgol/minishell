/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_token *token_create(t_allocator *allocator)
{
	t_token *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	self->kind = KIND_NO_KIND;
	self->str = 0;
	self->len = 0;
	self->extra = 0;
	assert(self != NULL);
	return (self);
}

void token_init(t_allocator *allocator, t_token *self, char *str)
{
	assert(allocator != NULL);
	assert(self != NULL);
	self->str = string_clone(allocator, str);
	self->len = string_length(str);
}

void token_deinit(t_allocator *allocator, t_token *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	self->kind = KIND_NO_KIND;
	self->len = 0;
	if (self->extra)
		token_payload_destroy(allocator, (t_token_payload *) self->extra);
	self->extra = 0;
	allocator->destroy(allocator, self->str);
}

void     token_print(t_token *self)
{
	if (self)
		print(1,"%s",self->str);
}

t_token *token_destroy(t_allocator *allocator, t_token *self)
{
	assert(self != NULL);
	assert(allocator != NULL);
	allocator->destroy(allocator, self);
	return (NULL);
}
