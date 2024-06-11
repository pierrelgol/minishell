/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:05:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/10 11:05:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_builtins_pwd *pwd_create(t_environment *env)
{
	t_builtins_pwd *self;

	self = memory_alloc(sizeof(t_builtins_pwd));
	if (!self)
		return (NULL);
	self->env = env;
	self->pwd = enviroment_get(self->env, "PWD");
	return (self);
}

bool pwd_print(t_builtins_pwd *self)
{
	self->pwd = enviroment_get(self->env, "PWD");
	print("%s\n", self->pwd);
	return (true);
}

t_builtins_pwd *pwd_destroy(t_builtins_pwd *self)
{
	if (self)
		memory_dealloc(self);
	return (NULL);
}
