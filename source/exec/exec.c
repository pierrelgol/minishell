/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:37:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/07 12:37:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_exec *exec_create(t_shell *shell, t_environment *env, t_linker *linker)
{
	t_exec *self;

	self = memory_alloc(sizeof(t_exec));
	if (!self)
		return (NULL);
	self->env = env;
	self->shell = shell;
	self->linker = linker;
	self->input = NULL;
	self->is_dirty = false;
	return (self);
}

t_vector *exec_execute(t_exec *self, t_vector *commands)
{
	(void)self;
	(void)commands;
	return (self->input);
}

t_exec *exec_clear(t_exec *self)
{
	if (!self->is_dirty)
		return (self);
	// where you cleanup
	return (self);
}

t_exec *exec_destroy(t_exec *self)
{
	if (self->is_dirty)
		exec_clear(self);
	memory_dealloc(self);
	return (NULL);
}
