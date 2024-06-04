/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:53:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 13:53:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_lexer	*lexer_create(void)
{
	t_lexer	*self;

	self = memory_alloc(sizeof(t_lexer));
	if (!self)
		return (NULL);
	self->delim = NULL;
	self->input = NULL;
	self->output = vector_create();
	if (!self->output)
	{
		memory_dealloc(self);
		return (NULL);
	}
	self->is_dirty = false;
	return (self);
}

t_lexer	*lexer_init(t_lexer *self, char *input, char *delim)
{
	self->delim = string_clone(delim);
	self->input = string_clone(input);
	self->is_dirty = true;
	return (self);
}

t_vector	*lexer_lex(t_lexer *self)
{
	char		**temp;
	uint64_t	i;

	temp = split(self->input, self->delim);
	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		vector_insert_at(self->output, (uintptr_t)string_clone(temp[i]), i);
		i += 1;
	}
	split_destroy(temp);
	self->is_dirty = true;
	return (self->output);
}

t_lexer	*lexer_clear(t_lexer *self)
{
	char	*temp;

	if (!self->is_dirty)
		return (self);
	it_save(self->output);
	while (!it_end(self->output))
	{
		temp = (char *)it_peek_curr(self->output);
		memory_dealloc(temp);
	}
	it_restore(self->output);
	vector_clear(self->output);
	memory_dealloc(self->delim);
	memory_dealloc(self->input);
	self->delim = NULL;
	self->input = NULL;
	self->is_dirty = true;
	return (self);
}

t_lexer	*lexer_destroy(t_lexer *self)
{
	if (!self)
		return (NULL);
	if (self->is_dirty)
		lexer_clear(self);
	vector_destroy(self->output);
	memory_dealloc(self->delim);
	memory_dealloc(self->input);
	memory_dealloc(self);
	return (NULL);
}
