/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:19:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:19:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_shell_tokenizer *shell_tokenizer_create(t_allocator *allocator, t_token_iter *iter)
{
	t_shell_tokenizer *tokenizer;

	tokenizer = allocator->create(allocator, sizeof(t_shell_tokenizer));
	if (!tokenizer)
		return (NULL);
	tokenizer->allocator = allocator;
	tokenizer->delimiters = bitset_init_empty();
	tokenizer->input = NULL;
	tokenizer->output = iter;
	return (tokenizer);
}

t_token_iter *tokenizer_tokenize(t_shell_tokenizer *tokenizer, char *input, char *delimiters)
{
	t_allocator *allocator;
	char       **raw_tokens;
	uint64_t     i;

	allocator = tokenizer->allocator;
	tokenizer->delimiters = bitset_init_from_str(delimiters);
	tokenizer->input = input;
	raw_tokens = string_split_any(allocator, tokenizer->input, &tokenizer->delimiters);
	i = 0;
	while (raw_tokens[i])
	{
		token_set_str(allocator, iter_peek_curr(tokenizer->output), raw_tokens[i]);
		iter_eat(tokenizer->output, 1);
		++i;
	}
	token_set_kind(iter_peek_curr(tokenizer->output), KIND_END_OF_TOK);
	iter_reset_start(tokenizer->output);
	tokenizer->output->count = i;
	allocator_destroy_split(allocator, raw_tokens);
	return (tokenizer->output);
}

void               tokenizer_clear(t_shell_tokenizer *tokenizer)
{
	if (tokenizer)
	{
		tokenizer->delimiters = bitset_init_empty();
		tokenizer->input = NULL;
	}
}

t_shell_tokenizer *shell_tokenizer_destroy(t_shell_tokenizer *tokenizer)
{
	t_allocator *allocator;

	if (tokenizer)
	{
		allocator = tokenizer->allocator;
		tokenizer->delimiters = bitset_init_empty();
		tokenizer->input = NULL;
		tokenizer->output = NULL;
		allocator->destroy(allocator, tokenizer);
	}
	return (NULL);
}
