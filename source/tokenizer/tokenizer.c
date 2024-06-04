/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:53:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 13:53:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_tokenizer *tokenizer_create(void)
{
	t_tokenizer *self;

	self = memory_alloc(sizeof(t_tokenizer));
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

t_tokenizer *tokenizer_init(t_tokenizer *self, char *input, char *delim)
{
	self->delim = string_clone(delim);
	self->input = string_clone(input);
	self->is_dirty = true;
	return (self);
}

t_vector *tokenizer_lex(t_tokenizer *self)
{
	char   **temp;
	t_token *token;
	uint64_t i;

	temp = split(self->input, self->delim);
	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		token = token_create(temp[i]);
		vector_insert_at(self->output, (uintptr_t) token, i);
		i += 1;
	}
	split_destroy(temp);
	self->is_dirty = true;
	return (self->output);
}

t_tokenizer *tokenizer_clear(t_tokenizer *self)
{
	t_token *temp;

	if (!self->is_dirty)
		return (self);
	it_save(self->output);
	while (!it_end(self->output))
	{
		temp = (t_token *) it_peek_curr(self->output);
		if (temp)
			token_destroy(temp);
		it_advance(self->output);
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

t_tokenizer *tokenizer_destroy(t_tokenizer *self)
{
	if (!self)
		return (NULL);
	if (self->is_dirty)
		tokenizer_clear(self);
	vector_destroy(self->output);
	memory_dealloc(self->delim);
	memory_dealloc(self->input);
	memory_dealloc(self);
	return (NULL);
}
