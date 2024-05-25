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

t_shell_lexer *shell_lexer_create(t_allocator *allocator)
{
	t_shell_lexer *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->buffer = token_buffer_create(allocator);
	self->tokenized = NULL;
	assert(self->buffer != NULL);
	return (self);
}

void shell_lexer_init(t_allocator *allocator, t_shell_lexer *self, char **tokenized)
{
	assert(allocator != NULL);
	assert(self != NULL);
	token_buffer_init(allocator, self->buffer, tokenized);
	if (DEBUG == 1)
	{
		print(1, "\nshell_lexer_init()\n");
		buffer_print(self->buffer);
		print(1, "\nshell_lexer()\n");
	}
}

void shell_lexer_deinit(t_allocator *allocator, t_shell_lexer *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	self->tokenized = NULL;
	token_buffer_deinit(allocator, self->buffer);
}

t_shell_lexer *shell_lexer_destroy(t_allocator *allocator, t_shell_lexer *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	allocator->destroy(allocator, self);
	return (NULL);
}
