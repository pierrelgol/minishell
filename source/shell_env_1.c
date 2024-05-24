/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:35:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 10:35:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_shell_env *shell_env_create(t_allocator *allocator, int32_t argc, char **argv, char **envp)
{
	t_shell_env *env;

	env = allocator->create(allocator, sizeof(t_shell_env));
	if (!env)
		return (NULL);
	env->allocator = allocator;
	env->argc = argc;
	env->argv = argv;
	env->envp = envp;
	env->keys = list_create(allocator);
	env->protected_keys = list_create(allocator);
	env->variables = table_create(allocator);
	env_init_default(env, allocator, env->variables, envp);
	env_init_customs(env, allocator, env->variables, envp);
	return (env);
}

void env_init_default(t_shell_env *env, t_allocator *allocator, t_table *variables, char **envp)
{
	char    *value;
	char    *key;
	uint64_t index;
	uint64_t i;

	i = 0;
	while (envp[i])
	{
		index = string_index_of_first_scalar(envp[i], '=');
		// print(1,"%s" ,key);
		key = string_nclone(allocator, envp[i], index);
		value = string_clone(allocator, &envp[i][index + 1]);
		table_entry_set(env->variables, key, (uintptr_t) value);
		list_push_back(env->keys, (uintptr_t) key);
		++i;
	}
}

void env_init_customs(t_shell_env *env, t_allocator *allocator, t_table *variables, char **envp)
{
	env_protected_put(env, string_clone(allocator, "PWD"), env_get(env, "PWD"));
	env_protected_put(env, string_clone(allocator, "MINI_COLOR"), YELLOW);
	env_protected_put(env, string_clone(allocator, "MINI_SYMB"), string_clone(allocator, "|> "));
}

bool env_contains(t_shell_env *env, char *key)
{
	return (env_get(env, key) != NULL);
}

bool env_protected_remove(t_shell_env *env, char *key)
{
	t_node *node;

	node = env->protected_keys->head;
	while (node)
	{
		if (string_compare((char *) node->data, key) == 0)
			return (false);
		node = node->next;
	}
	return (env_remove(env, key));
}
