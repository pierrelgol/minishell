/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:31:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_prompt *shell_prompt_create(t_allocator *allocator, t_shell_env *env)
{
	t_shell_prompt *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->env = env;
	self->prompt = NULL;
	return (self);
}

void shell_prompt_init(t_allocator *allocator, t_shell_prompt *self)
{
	char *pwd;
	char *temp1;
	char *temp2;

	assert(allocator != NULL);
	assert(self != NULL);
	pwd = shell_env_get(self->env, "PWD");
	temp1 = string_join_sequence(allocator, YELLOW, pwd);
	assert(temp1 != NULL);
	temp2 = string_join_sequence(allocator, temp1, " |> ");
	assert(temp2 != NULL);
	self->prompt = string_join_sequence(allocator, temp2, RESET);
	assert(self->prompt != NULL);
	allocator->destroy(allocator, temp1);
	allocator->destroy(allocator, temp2);
}

char *shell_prompt_get(t_shell_prompt *self)
{
	return (self->prompt);
}

void shell_prompt_deinit(t_allocator *allocator, t_shell_prompt *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	if (self->prompt)
	{
		allocator->destroy(allocator, self->prompt);
		self->prompt = NULL;
	}
}

void shell_prompt_print(t_shell_prompt *prompt)
{
	print(1, "--------------------------------\n");
	print(1, "shell_prompt ouput :\n");
	print(1, "prompt : [%s]\n",prompt->prompt);
	print(1, "--------------------------------\n");
}

t_shell_prompt *shell_prompt_destroy(t_allocator *allocator, t_shell_prompt *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	allocator->destroy(allocator, self);
	return (NULL);
}
