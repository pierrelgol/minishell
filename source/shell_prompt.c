/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:18:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 10:18:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_shell_prompt *shell_prompt_create(t_allocator *allocator, t_shell_env *env)
{
	t_shell_prompt *prompt;

	prompt = allocator->create(allocator, sizeof(t_shell_prompt));
	if (!prompt)
		return (NULL);
	prompt->allocator = allocator;
	prompt->env = env;
	prompt->color = NULL;
	prompt->path = NULL;
	prompt->symbol = NULL;
	return (prompt);
}

void prompt_build(t_shell_prompt *prompt)
{
	t_allocator *allocator;
	char        *temp;

	if (!prompt)
		return;
	allocator = prompt->allocator;
	prompt->path = env_protected_get(prompt->env, "PWD", "(-_-)");
	prompt->color = env_protected_get(prompt->env, "MINI_COLOR", YELLOW);
	prompt->symbol = env_protected_get(prompt->env, "MINI_SYMB", "|>\n");
	temp = string_join_scalar_sequence(allocator, prompt->color, ' ', prompt->path);
	prompt->prompt = string_join_scalar_sequence(allocator, temp, ' ', prompt->symbol);
	allocator->destroy(allocator, temp);
	temp = prompt->prompt;
	prompt->prompt = string_join_sequence(allocator, temp, RESET);
	allocator->destroy(allocator, temp);
}

char *prompt_get(t_shell_prompt *prompt)
{
	return (prompt->prompt);
}

void prompt_clear(t_shell_prompt *prompt)
{
	t_allocator *allocator;

	if (!prompt)
		return;
	allocator = prompt->allocator;
	allocator->destroy(allocator, prompt->prompt);
	prompt->color = NULL;
	prompt->path = NULL;
	prompt->symbol = NULL;
}

t_shell_prompt *shell_prompt_destroy(t_shell_prompt *prompt)
{
	t_allocator *allocator;

	if (!prompt)
		return (NULL);
	allocator = prompt->allocator;
	allocator->destroy(allocator, prompt->prompt);
	prompt->allocator = NULL;
	prompt->env = NULL;
	prompt->color = NULL;
	prompt->path = NULL;
	prompt->symbol = NULL;
	allocator->destroy(allocator, prompt);
	return (NULL);
}
