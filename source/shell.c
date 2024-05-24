/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:08:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/22 12:08:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_shell *shell_create(t_allocator *allocator, int32_t argc, char **argv, char **envp)
{
	t_shell *shell;

	shell = allocator->create(allocator, sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->allocator = allocator;
	shell->environment = shell_env_create(allocator, argc, argv, envp);
	shell->prompt = shell_prompt_create(allocator, shell->environment);
	shell->input = shell_input_create(allocator, shell->prompt);
	shell->tokens = token_vector_create(allocator, MAX_TOKENS);
	shell->iter = iter_create(allocator, shell->tokens);
	shell->tokenizer = shell_tokenizer_create(allocator, shell->iter);
	shell->lexer = shell_lexer_create(allocator, shell->iter);
	shell->parser = shell_parser_create(allocator, shell->iter);
	return (shell);
}

void shell_run(t_shell *self)
{
	while (true)
	{
		prompt_build(self->prompt);
		self->line = input_get(self->input);
		if (!self->line)
			break;
		self->iter = tokenizer_tokenize(self->tokenizer, self->line, " |&<>;$=");
		self->iter = lexer_lex(self->lexer);
		shell_clear(self);
	}
}

void shell_clear(t_shell *self)
{
	prompt_clear(self->prompt);
	input_clear(self->input);
	// @TODO 
	token_vector_clear(self->allocator, self->tokens);
	tokenizer_clear(self->tokenizer);
	lexer_clear(self->lexer);
	iter_reset_start(self->iter);
}

t_shell *shell_destroy(t_shell *self)
{
	t_allocator *allocator;

	if (!self)
		return (NULL);
	allocator = self->allocator;
	shell_env_destroy(self->environment);
	shell_prompt_destroy(self->prompt);
	shell_input_destroy(self->input);
	shell_tokenizer_destroy(self->tokenizer);
	shell_lexer_destroy(self->lexer);
	shell_parser_destroy(self->parser);
	iter_destroy(self->iter);
	// @TODO
	token_vector_destroy(self->allocator, self->tokens);
	allocator->destroy(allocator, self);
	gpa_deinit(allocator);
	return (NULL);
}
