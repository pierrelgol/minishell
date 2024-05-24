/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:35:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 10:35:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

bool env_remove(t_shell_env *env, char *key)
{
	uint64_t index;
	t_node  *node;

	index = 0;
	node = env->keys->head;
	while (node)
	{
		if (string_compare((char *) node->data, key) == 0)
		{
			list_pop_at(env->keys, index);
			table_body_remove(env->variables, key);
			return (true);
		}
		node = node->next;
		++index;
	}
	return (false);
}

char *env_get(t_shell_env *env, char *key)
{
	char *result;

	result = (char *) table_entry_get(env->variables, key);
	if (!result)
		return (NULL);
	return (result);
}

bool env_protected_put(t_shell_env *env, char *key, char *value)
{
	t_node *node;

	if (!env_get(env, key))
		return (env_put(env, key, value));
	else
	{
		node = env->protected_keys->head;
		while (node)
		{
			if (string_compare((char *) node->data, key) == 0)
				return (false);
			node = node->next;
		}
		list_push_front(env->protected_keys, (uintptr_t) string_clone(env->allocator, key));
		return (env_put(env, key, value));
	}
}

bool env_put(t_shell_env *env, char *key, char *value)
{
	if (!env_get(env, key))
	{
		list_push_front(env->keys, (uintptr_t) string_clone(env->allocator, key));
		table_entry_set(env->variables, key, (uintptr_t)value);
		return (true);
	}
	else
		table_entry_set(env->variables, key, (uintptr_t)value);		
	return (true);
}

bool         env_print_one(t_shell_env *env, char *key)
{
	if (env_get(env, key))
	{
		print(1, "%s=%s\n",key, env_get(env,key));
		return (true);
	}
	return (false);
}
