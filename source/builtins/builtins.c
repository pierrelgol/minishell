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
	self->cd_cwd = builtins_sync_cd(self);
	self->is_dirty = false;
	return (self);
}

t_builtins *builtins_sync(t_builtins *self)
{
	self->is_dirty = true;
	return (self);
}

t_builtins *builtins_clear(t_builtins *self)
{
	self->is_dirty = false;
	return (self);
}

t_builtins *builtins_destroy(t_builtins *self)
{
	if (self->is_dirty)
		builtins_clear(self);
	memory_dealloc(self);
	return (NULL);
}
