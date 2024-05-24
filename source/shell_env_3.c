/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:10:44 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:10:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int32_t key_compare(uintptr_t k1, uintptr_t k2)
{
	char *p1;
	char *p2;

	p1 = (char *) k1;
	p2 = (char *) k2;
	while (*p1 && *p1 == *p2)
	{
		++p1;
		++p2;
	}
	return ((uint8_t) *p1 - (uint8_t) *p2);
}

bool env_print_all(t_shell_env *env, bool sort)
{
	t_node *node;

	list_sort(&env->keys->head, key_compare);
	node = env->keys->head;
	while (node)
	{
		if (node->data)
			env_print_one(env, (char *) node->data);
		node = node->next;
	}
	return (true);
}

t_shell_env *shell_env_destroy(t_shell_env *env)
{
	t_allocator *allocator;

	if (!env)
		return (NULL);
	allocator = env->allocator;
	list_destroy(env->keys);
	list_destroy(env->protected_keys);
	table_destroy(env->variables);
	allocator->destroy(allocator, env);
	return (NULL);
}

char        *env_protected_get(t_shell_env *env, char *key, char *def)
{
	char	*result;

	result = env_get(env, key);
	if (!result)
		return (def);
	return (result);
}
