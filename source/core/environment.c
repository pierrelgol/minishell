/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_env *shell_env_create(t_allocator *allocator)
{
	t_shell_env *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->keys = vector_create(allocator);
	self->value = vector_create(allocator);
	self->vars = table_create(allocator);
	return (self);
}

void shell_env_init(t_allocator *allocator, t_shell_env *self, char **envp)
{
	uint64_t i;
	char    *key;
	char    *value;

	assert(allocator != NULL);
	assert(self != NULL);
	assert(envp != NULL);
	self->envp = envp;

	i = 0;
	while (envp[i])
	{
		from_string_to_key_value_pair(allocator, envp[i], &key, &value);
		shell_env_set(self, key, value);
		allocator->destroy(allocator, key);
		allocator->destroy(allocator, value);
		++i;
	}
}

bool shell_env_del(t_shell_env *self, char *key)
{
	char    *maybe_key;
	uint64_t i;

	i = 0;
	assert(self != NULL);
	assert(key != NULL);
	while (vector_end_of_vec(self->keys, i))
	{
		maybe_key = (char *) vector_peek_at(self->keys, i);
		if (maybe_key && string_compare(maybe_key, key) == 0)
		{
			table_body_remove(self->vars, key);
			vector_remove_at(self->keys, i);
			return (true);
		}
		++i;
	}
	return (false);
}

char *shell_env_get(t_shell_env *self, char *key)
{
	char *maybe_value;

	assert(self != NULL);
	assert(key != NULL);
	maybe_value = (char *) table_entry_get(self->vars, key);
	if (!maybe_value)
		return (NULL);
	return (maybe_value);
}

bool shell_env_set(t_shell_env *self, char *key, char *value)
{
	char *copied_key;
	char *copied_value;
	char *temp;

	if (!shell_env_get(self, key))
	{
		copied_key = string_clone(self->allocator, key);
		vector_insert_back(self->keys, (uintptr_t) copied_key);
		copied_value = string_clone(self->allocator, value);
		vector_insert_back(self->value, (uintptr_t) copied_value);
		table_entry_set(self->vars, copied_key, (uintptr_t) copied_value);
		return (false);
	}
	else
	{
		copied_value = string_clone(self->allocator, value);
		vector_insert_back(self->value, (uintptr_t) copied_value);
		table_entry_set(self->vars, key, (uintptr_t) value);
		return (true);
	}
}

void shell_env_print_one(t_shell_env *self, char *key)
{
	char *maybe_value;

	maybe_value = shell_env_get(self, key);
	assert(maybe_value != NULL);

	print(1, "%s=%s\n", key, maybe_value);
}

void shell_env_print_all(t_shell_env *self)
{
	char    *copied_key;
	uint64_t i;

	i = 0;
	while (vector_end_of_vec(self->keys, i))
	{
		copied_key = (char *) vector_peek_at(self->keys, i);
		if (copied_key)
			shell_env_print_one(self, copied_key);
		++i;
	}
}

void shell_env_deinit(t_allocator *allocator, t_shell_env *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	self->envp = NULL;
}

t_shell_env *shell_env_destroy(t_allocator *allocator, t_shell_env *self)
{
	char    *elem;
	uint64_t i;

	assert(self != NULL);
	assert(allocator != NULL);
	i = 0;
	while (vector_end_of_vec(self->keys, i))
	{
		elem = (char *) vector_pop(self->keys);
		if (elem)
			allocator->destroy(allocator, elem);
		++i;
	}
	i = 0;
	while (vector_end_of_vec(self->value, i))
	{
		elem = (char *) vector_pop(self->value);
		if (elem)
			allocator->destroy(allocator, elem);
		++i;
	}
	table_destroy(self->vars);
	vector_destroy(self->keys);
	vector_destroy(self->value);
	allocator->destroy(allocator, self);
	return (NULL);
}
