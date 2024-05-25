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

t_shell_tokenizer *shell_tokenizer_create(t_allocator *allocator)
{
	t_shell_tokenizer *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	self->input = NULL;
	self->tokenized = NULL;
	self->delimiters = bitset_init_empty();
	assert(self != NULL);
	return (self);
}

void shell_tokenizer_init(t_allocator *allocator, t_shell_tokenizer *self, char *line, char *delimiters)
{
	assert(allocator != NULL);
	assert(self != NULL);
	assert(delimiters != NULL);
	self->input = string_clone(allocator, line);
	self->delimiters = bitset_init_from_str(delimiters);
	self->tokenized = string_split_any(allocator, self->input, &self->delimiters);
}

char **shell_tokenizer_get(t_shell_tokenizer *self)
{
	if (DEBUG == 1)
	{
		print(1, "\nshell_tokenizer_get()\n");
		for(int i = 0; self->tokenized[i]; i++)
		{
			print(1, "[%d][%s]\n",i, self->tokenized[i]);
		}
		print(1, "\n");
	}
	return (self->tokenized);
}

void shell_tokenizer_deinit(t_allocator *allocator, t_shell_tokenizer *self)
{
	uint64_t i;
	char    *tok;

	assert(allocator != NULL);
	assert(self != NULL);
	i = 0;
	while (self->tokenized[i])
	{
		tok = self->tokenized[i];
		if (!tok)
			break;
		allocator->destroy(allocator, tok);
		++i;
	}
	allocator->destroy(allocator, self->tokenized);
	if (self->input)
		allocator->destroy(allocator, self->input);
	self->input = NULL;
	self->delimiters = bitset_init_empty();
	self->tokenized = NULL;
}

t_shell_tokenizer *shell_tokenizer_destroy(t_allocator *allocator, t_shell_tokenizer *self)
{
	assert(self != NULL);
	assert(allocator != NULL);
	allocator->destroy(allocator, self);
	return (NULL);
}
