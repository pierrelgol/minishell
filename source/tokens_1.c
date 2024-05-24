/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:33:47 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:33:47 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_token *token_create(t_allocator *allocator)
{
	t_token	*token;

	token = allocator->create(allocator, sizeof(t_token));
	if (!token)
		return (NULL);
	token->extra = 0;
	token->kind = KIND_NO_KIND;
	token->len = 0;
	token->str = NULL;
	return (token);
}

t_token *token_set_str(t_allocator *allocator, t_token *self, char *string)
{
	if (!self)
		return (NULL);
	self->str = string_clone(allocator, string);
	self->len = string_length(self->str);
	return (self);
}

t_token *token_set_kind(t_token *self, t_token_kind kind)
{
	if (!self)
		return (NULL);
	self->kind = kind;
	return (self);
}

t_token *token_set_extra(t_token *self, uintptr_t extra)
{
	if (!self)
		return (NULL);
	self->extra = extra;
	return (self);
}

t_token *token_clear(t_allocator *allocator, t_token *tok)
{
	if (!tok)
		return (NULL);
	allocator->destroy(allocator, tok->str);
	tok->str = NULL;
	tok->kind = KIND_END_OF_TOK;
	tok->extra = 0;
	tok->len = 0;
	return (tok);
}

