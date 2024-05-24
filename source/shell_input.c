/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:52:13 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 08:52:17 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_shell_input	*shell_input_create(t_allocator *allocator, t_shell_prompt *prompt)
{
	t_shell_input	*input;

	input = allocator->create(allocator, sizeof(t_shell_input));
	if (!input)
		return (NULL);
	input->allocator = allocator;
	input->prompt = prompt;
	input->line = NULL;
	input->signal = rl_clear_signals();
	return (input);
}

char          *input_get(t_shell_input *input)
{
	char	*temp;

	temp = readline(prompt_get(input->prompt));
	if (temp)
	{
		input->line = string_clone(input->allocator, temp);
		free(temp);
	}
	else
		input->line = NULL;
	return (input->line);
}

void           input_clear(t_shell_input *input)
{
	t_allocator	*allocator;

	if (!input)
		return;
	allocator = input->allocator;
	allocator->destroy(allocator, input->line);
	input->line = NULL;
}

t_shell_input *shell_input_destroy(t_shell_input *input)
{
	t_allocator	*allocator;

	if (!input)
		return (NULL);
	allocator = input->allocator;
	allocator->destroy(allocator, input->line);
	input->line = NULL;
	input->prompt = NULL;
	input->allocator = NULL;
	allocator->destroy(allocator, input);
	return (NULL);
}

