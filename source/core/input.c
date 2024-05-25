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

t_shell_input *shell_input_create(t_allocator *allocator)
{
	t_shell_input *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->line = NULL;
	return (self);
}

void shell_input_init(t_allocator *allocator, t_shell_input *self, char *prompt)
{
	char *temp;

	assert(allocator != NULL);
	assert(self != NULL);
	assert(prompt != NULL);
	temp = readline(prompt);
	if (!temp)
		self->line = NULL;
	else
	{
		self->line = allocator->dupz(allocator, temp, string_length(temp));
		assert(self->line != NULL);
		free(temp);
	}
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

t_shell_input *shell_input_destroy(t_allocator *allocator, t_shell_input *self)
{
	assert(self != NULL);
	assert(allocator != NULL);
	allocator->destroy(allocator, self);
	return (NULL);
}
