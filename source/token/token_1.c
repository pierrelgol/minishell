/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:23:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 15:23:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_token *token_create(char *ptr)
{
	t_token *self;

	self = memory_alloc(sizeof(t_token));
	self->ptr = string_clone(ptr);
	self->len = string_length(self->ptr);
	self->kind = KIND_NO_KIND;
	self->extra = 0;
	return (self);
}

void         token_print(t_token *token)
{
	if (token)
		print("Token->");
	else
		print("(null)->");
}

char        *token_get_str(t_token *self)
{
	return self->ptr;
}

t_token_kind token_get_kind(t_token *self)
{
	return self->kind;
}

uintptr_t    token_get_extra(t_token *self)
{
	return (self->extra);
}
