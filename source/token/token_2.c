/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:23:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 15:23:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void token_set_str(t_token *self, char *str)
{
	if (self->ptr)
		memory_dealloc(self->ptr);
	self->ptr = string_clone(str);
	self->len = string_length(self->ptr);
}

void token_set_kind(t_token *self, t_token_kind kind)
{
	self->kind = kind;
}

void token_set_extra(t_token *self, uintptr_t extra)
{
	self->extra = extra;
}

t_token *token_destroy(t_token *self)
{
	if (!self)
		return (NULL);
	if (self->ptr)
		memory_dealloc(self->ptr);
	self->len = 0;
	self->extra = 0;
	self->kind = KIND_NO_KIND;
	memory_dealloc(self);
	return (NULL);
}
