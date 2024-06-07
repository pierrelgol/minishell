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
	// @STEP10 we get the prompt --> ./source/prompt/prompt.c
	const char *prompt = prompt_get(self->prompt);

	if (DIRECT_IO)
	{
		// @STEP13A if we compiled with the flag -DDIRECT_IO=1
		// we skip the realine() and simply clone the argv[self->index]
		// until there is no more arguments this is the best mode to
		// test inputs quickly and randomnly
		if (self->index < self->argc)
			self->line = string_clone(self->argv[self->index++]);
		else
			self->line = NULL;
	}
	else
	{
		// @STEP13B if we compiled with the flag -DDIRECT_IO=0
		// we call readline with our prompt(prompt);
		self->line = readline(prompt);
	}
	// @INFO the self->is_dirty is in every structure that does memory
	// allocation temporarily, the goal is to prevent double free and
	// eventual memory  leaks, when a structure does memory allocation
	// we set the is_dirty to true, this way if we have to quit before
	// we get the opportunity to call shell_clear(), than during the 
	// shell_destroy() call, every structure XXXXXX_destroy() will be
	// called and inside each of these function there is a backup call
	// to the XXXXXX_clear() function of each object
	//
	// t_xxxxx *xxxxx_destroy(t_xxxx *self)
	// {
	//   if (self->is_dirty)
	//       xxxxx_clear(self);
	//   
	//   memory_dealloc(self);
	//   return (NULL);
	// }
	//
	//
	self->is_dirty = true;
	// @STEP14 --> ./source/core/shell.c
	return (self->line);
}

t_input *input_destroy(t_input *self)
{
	if (self->is_dirty)
		input_clear(self);
	memory_dealloc(self);
	return (NULL);
}
