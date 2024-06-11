/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:00:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/11 10:00:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_builtins_env *env_create(t_environment *env)
{
	t_builtins_env *self;

	self = memory_alloc(sizeof(t_builtins_env));
	if (!self)
		return (NULL);
	self->env = env;
	self->var = self->env->keys;
	return (self);
}

bool env_put(t_builtins_env *self, char *variable, char *value)
{
	if (!variable || !value)
		return (false);
	enviroment_put(self->env, variable, value);
	return (true);
}

bool env_print_one(t_builtins_env *self, char *variable)
{
	char *value;

	value = enviroment_get(self->env, variable);
	if (value)
	{
		print("%s=%s\n", variable, value);
	}
	return (false);
}

bool env_print_all(t_builtins_env *self)
{
	char *key;

	it_save(self->var);
	while (!it_end(self->var))
	{
		key = (char *) it_peek_curr(self->var);
		if (key)
			env_print_one(self, key);
		it_advance(self->var);
	}
	it_restore(self->var);
	return (true);
}

t_builtins_env *env_destroy(t_builtins_env *self)
{
	if (self)
		memory_dealloc(self);
	return (NULL);
}
