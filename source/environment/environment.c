/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:08:55 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 14:08:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_environment	*environment_create(char **envp)
{
	t_environment	*self;

	self = memory_alloc(sizeof(t_environment));
	if (!self)
		return (NULL);
	self->keys = vector_create_with_capacity(1024);
	self->vars = hashmap_create(1024);
	self->is_dirty = false;
	if (!self->keys || !self->vars)
	{
		if (self->keys)
			vector_destroy(self->keys);
		if (self->vars)
			hashmap_destroy(self->vars);
		memory_dealloc(self);
		return (NULL);
	}
	environment_build(self, envp);
	return (self);
}

t_environment	*environment_build(t_environment *self, char **envp)
{
	uint64_t	index;
	uint64_t	i;
	char		*k;
	char		*v;

	i = 0;
	while (envp[i])
	{
		index = string_index_of(envp[i], '=');
		k = string_nclone(envp[i], index);
		v = string_clone(&envp[i][index + 1]);
		hashmap_put(self->vars, k, v);
		vector_insert_back(self->keys, (uintptr_t)k);
		memory_dealloc(v);
		i += 1;
	}
	vector_sort(self->keys, enviroment_compare);
	self->is_dirty = true;
	return (self);
}

int64_t	enviroment_compare(uintptr_t a, uintptr_t b)
{
	return (string_compare((char *)a, (char *)b));
}

bool	enviroment_put(t_environment *self, char *variable, char *value)
{
	if (!hashmap_get(self->vars, variable))
		vector_insert_sorted(self->keys, (uintptr_t)string_clone(variable),
			enviroment_compare);
	return (hashmap_put(self->vars, variable, value));
}

char	*enviroment_get(t_environment *self, char *variable)
{
	return (hashmap_get(self->vars, variable));
}

bool	enviroment_rem(t_environment *self, char *variable)
{
	int64_t	index;

	index = vector_search(self->keys, (uintptr_t)variable, enviroment_compare);
	if (index == -1)
		return (false);
	vector_remove_at(self->keys, index);
	return (hashmap_del(self->vars, variable));
}

t_environment	*environment_destroy(t_environment *self)
{
	char	*temp;

	if (!self)
		return (NULL);
	it_save(self->keys);
	while (!it_end(self->keys))
	{
		temp = (char *)it_peek_curr(self->keys);
		if (temp)
			memory_dealloc(temp);
		it_advance(self->keys);
	}
	it_restore(self->keys);
	vector_destroy(self->keys);
	hashmap_destroy(self->vars);
	memory_dealloc(self);
	return (NULL);
}
