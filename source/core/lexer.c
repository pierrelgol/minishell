/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_lexer *shell_lexer_create(t_allocator *allocator, t_shell_tokenizer *tokenizer)
{
	t_shell_lexer *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->tokenizer = tokenizer;
	self->it = it_create(allocator);
	return (self);
}

void shell_lexer_init(t_allocator *allocator, t_shell_lexer *self)
{
	t_vector *tokenized;
	t_token *token;
	uint64_t i;

	assert(allocator != NULL);
	assert(self != NULL);
	i = 0;
	tokenized = shell_tokenizer_get(self->tokenizer);
	while (!vector_end(tokenized, i))
	{
		vector_insert_at(self->it->vec, vector_peek_at(tokenized, i), i);
		++i;
	}
	shell_lexer_lex(self);
}

t_iterator *shell_lexer_get(t_shell_lexer *self)
{
	return (self->it);
}

void shell_lexer_deinit(t_allocator *allocator, t_shell_lexer *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	it_deinit(self->it);
}

void shell_lexer_print(t_shell_lexer *self)
{
	t_token *token;
	int32_t  i;

	i = 0;
	print(1, "--------------------------------\n");
	print(1, "shell_lexer ouput :\n");
	assert(self->it->vec->count = self->tokenizer->output->count);
	it_save(self->it);
	while (!it_end(self->it))
	{
		token = (t_token *) it_peekcurr(self->it);
		if (token)
			print(1, "[%d][%s][%s]\n", i, token->str, getkind(token->kind));
		it_next(self->it);
		++i;
	}
	print(1, "--------------------------------\n");
	it_restore(self->it);
}

t_shell_lexer *shell_lexer_destroy(t_allocator *allocator, t_shell_lexer *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	it_destroy(self->it);
	allocator->destroy(allocator, self);
	return (NULL);
}
