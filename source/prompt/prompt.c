/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:43:08 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 14:43:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_prompt	*prompt_create(t_environment *env)
{
	t_prompt	*self;

	self = memory_alloc(sizeof(t_prompt));
	if (!self)
		return (NULL);
	self->env = env;
	self->prompt = NULL;
	self->is_dirty = false;
	return (self);
}

char	*prompt_get(t_prompt *self)
{
	const char	*pwd = enviroment_get(self->env, "PWD");
	const char	*usr = enviroment_get(self->env, "USER");
	const char	*symbol = " |> ";
	const char	*sep = " ";
	char		*temp;

	temp = string_join(usr, sep);
	self->prompt = string_join(temp, pwd);
	memory_dealloc(temp);
	temp = string_join(self->prompt, symbol);
	memory_dealloc(self->prompt);
	self->prompt = temp;
	self->is_dirty = true;
	return (self->prompt);
}

t_prompt	*prompt_clear(t_prompt *self)
{
	if (self->prompt)
		memory_dealloc(self->prompt);
	self->prompt = NULL;
	self->is_dirty = false;
	return (self);
}

t_prompt	*prompt_destroy(t_prompt *self)
{
	if (self->is_dirty)
		prompt_clear(self);
	memory_dealloc(self);
	return (NULL);
}
