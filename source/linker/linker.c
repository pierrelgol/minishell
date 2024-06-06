/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:05:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/06 13:05:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_linker *linker_create(t_environment *env)
{
	t_linker *self;

	self = memory_alloc(sizeof(t_linker));
	if (!self)
		return (NULL);
	self->env = env;
	self->input = NULL;
	self->output = NULL;
	self->paths = NULL;
	self->is_dirty = false;
	return (self);
}

t_linker *linker_init(t_linker *self, char *additional_dir)
{
	(void)additional_dir;
	self->paths = simple_split(enviroment_get(self->env, "PATH"), ':');
	self->is_dirty = true;
	return (self);
}

char *linker_make_path(t_linker *self, char *root, char *maybe_path)
{
	char *result;
	char *temp;

	(void) self;
	temp = string_join(root, "/");
	result = string_join(temp, maybe_path);
	memory_dealloc(temp);
	return (result);
}

char *linker_resolve(t_linker *self, char *maybe_path, char flag)
{
	uint64_t i;
	char    *path;

	if (!self->is_dirty)
		linker_init(self, NULL);
	if (flag == 'x' && linker_resolve_exe(self, maybe_path))
		return (maybe_path);
	if (flag == 'f' && linker_resolve_path(self, maybe_path))
		return (maybe_path);
	i = 0;
	while (self->paths[i])
	{
		path = linker_make_path(self, self->paths[i++], maybe_path);
		if (flag == 'x' && linker_resolve_exe(self, path))
			return (path);
		if (flag == 'f' && linker_resolve_path(self, path))
			return (path);
		memory_dealloc(path);
	}
	self->is_dirty = true;
	return (NULL);
}

bool linker_resolve_exe(t_linker *self, char *exe)
{
	(void) self;
	return (access(exe, X_OK) == 0);
}

bool linker_resolve_path(t_linker *self, char *path)
{
	(void) self;
	return (access(path, F_OK) == 0);
}

t_linker *linker_clear(t_linker *self)
{
	if (self->is_dirty)
	{
		split_destroy(self->paths);
		self->paths = NULL;
		self->input = NULL;
		self->output = NULL;
		self->is_dirty = false;
	}
	return (self);
}

t_linker *linker_destroy(t_linker *self)
{
	if (!self)
		return (NULL);
	if (self->is_dirty)
		linker_clear(self);
	memory_dealloc(self);
	return (NULL);
}
