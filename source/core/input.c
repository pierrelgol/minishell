/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_input *shell_input_create(t_allocator *allocator, t_shell *shell, t_shell_prompt *prompt)
{
	t_shell_input *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->shell = shell;
	self->prompt = prompt;
	self->line = NULL;
	return (self);
}

void shell_input_init(t_allocator *allocator, t_shell_input *self)
{
	char *prompt;
	char *temp;

	assert(allocator != NULL);
	assert(self != NULL);
	prompt = shell_prompt_get(self->prompt);
	if (DIRECT_IO)
		temp = direct_io(self->shell);
	else
	{
		temp = readline(prompt);
		if (!temp)
			self->line = NULL;
	}
	if (temp != NULL)
	{
		self->line = allocator->dupz(allocator, temp, string_length(temp));
		assert(self->line != NULL);
		if (!DIRECT_IO)
			free(temp);
	}
	else
		self->line = NULL;
}

char *shell_input_get(t_shell_input *self)
{
	return (self->line);
}

void shell_input_deinit(t_allocator *allocator, t_shell_input *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	if (self->line)
	{
		allocator->destroy(allocator, self->line);
		self->line = NULL;
	}
}

void shell_input_print(t_shell_input *self)
{
	print(1, "--------------------------------\n");
	print(1, "shell_input ouput :\n");
	print(1, "input : [%s]\n", self->line);
	print(1, "--------------------------------\n");
}

t_shell_input *shell_input_destroy(t_allocator *allocator, t_shell_input *self)
{
	assert(self != NULL);
	assert(allocator != NULL);
	allocator->destroy(allocator, self);
	return (NULL);
}
