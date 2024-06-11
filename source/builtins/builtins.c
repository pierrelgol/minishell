/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:08:47 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/10 11:08:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_builtins *builtins_create(t_environment *env)
{
	t_builtins *self;

	self = memory_alloc(sizeof(t_builtins));
	if (!self)
		return (NULL);
	self->env = env;
	self->blt_cd = cd_create(env);
	self->blt_echo = echo_create(env);
	self->blt_env = env_create(env);
	self->blt_export = export_create(env);
	self->blt_unset = unset_create(env);
	self->blt_pwd = pwd_create(env);
	return (self);
}


t_builtins *builtins_destroy(t_builtins *self)
{
	if (self)
	{
		self->blt_cd = cd_destroy(self->blt_cd);
		self->blt_echo = echo_destroy(self->blt_echo);
		self->blt_env = env_destroy(self->blt_env);
		self->blt_export = export_destroy(self->blt_export);
		self->blt_unset = unset_destroy(self->blt_unset);
		self->blt_pwd = pwd_destroy(self->blt_pwd);
		memory_dealloc(self);
	}
	return (NULL);
}
