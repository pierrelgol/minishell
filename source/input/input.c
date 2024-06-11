/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:03:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 14:03:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_input *input_create(t_environment *env, t_prompt *prompt, int64_t argc, char **argv)
{
	t_input *self;

	self = memory_alloc(sizeof(t_input));
	if (!self)
		return (NULL);
	self->is_dirty = false;
	self->prompt = prompt;
	self->line = NULL;
	self->argc = argc;
	self->argv = argv;
	self->env = env;
	self->index = 1;
	return (self);
}

t_input *input_clear(t_input *self)
{
	if (!self->is_dirty)
		return (self);
	if (self->line)
		memory_dealloc(self->line);
	self->line = NULL;
	self->is_dirty = false;
	return (self);
}

char *input_get(t_input *self)
{
	const char *prompt = prompt_get(self->prompt);

	if (DIRECT_IO)
	{
		if (self->index < self->argc)
			self->line = string_clone(self->argv[self->index++]);
		else
			self->line = NULL;
	}
	else
		self->line = readline(prompt);
	self->is_dirty = true;
	return (self->line);
}

t_input *input_destroy(t_input *self)
{
	if (self->is_dirty)
		input_clear(self);
	memory_dealloc(self);
	return (NULL);
}
