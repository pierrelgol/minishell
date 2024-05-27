/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_tokenizer *shell_tokenizer_create(t_allocator *allocator, t_shell_input *input, char *delimiters)
{
	t_shell_tokenizer *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->input = input;
	self->split = NULL;
	self->output = vector_create(allocator);
	self->bitset = bitset_init_from_str(delimiters);
	return (self);
}

void shell_tokenizer_init(t_allocator *allocator, t_shell_tokenizer *self)
{
	char   **split;
	char    *input;
	t_token *token;
	uint64_t i;

	assert(allocator != NULL);
	assert(self != NULL);
	input = shell_input_get(self->input);
	split = string_split_any(allocator, input, &self->bitset);
	if (split)
	{
		i = 0;
		self->split = split;
		while (self->split[i])
		{
			token = token_create(allocator);
			token->kind = KIND_NO_KIND;
			token->str = self->split[i++];
			vector_enqueue(self->output, (uintptr_t) token);
		}
	}
}

t_vector *shell_tokenizer_get(t_shell_tokenizer *self)
{
	return (self->output);
}

void shell_tokenizer_deinit(t_allocator *allocator, t_shell_tokenizer *self)
{
	uint64_t i;
	t_token *token;

	assert(allocator != NULL);
	assert(self != NULL);
	if (self->split)
	{
		i = 0;
		while (self->split[i])
		{
			allocator->destroy(allocator, self->split[i++]);
			token = (t_token *) vector_dequeue(self->output);
			token_destroy(allocator, token);
		}
		allocator->destroy(allocator, self->split);
		self->split = NULL;
	}
	vector_clear(self->output);
}

void shell_tokenizer_print(t_shell_tokenizer *self)
{
	int32_t i;
	t_token *token;

	i = 0;
	print(1, "--------------------------------\n");
	print(1, "shell_tokenizer ouput :\n");
	while (!vector_end(self->output, i))
	{
		token = (t_token*) vector_peek_at(self->output, i);
		if (token)
			print(1, "[%d][%s]\n", i, token->str);
		++i;
	}
	print(1, "--------------------------------\n");
}

t_shell_tokenizer *shell_tokenizer_destroy(t_allocator *allocator, t_shell_tokenizer *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	allocator->destroy(allocator, self);
	return (NULL);
}
