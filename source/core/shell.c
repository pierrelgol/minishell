/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:29:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 13:29:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell *shell_create(int32_t argc, char **argv, char **envp)
{
	t_shell *self;

	self = (t_shell *) memory_alloc(sizeof(t_shell));
	if (!self)
		return (NULL);
	self->argc = argc;
	self->argv = argv;
	self->envp = envp;
	self->env = environment_create(envp);
	self->prompt = prompt_create(self->env);
	self->input = input_create(self->env, self->prompt, argc, argv);
	self->tokenizer = tokenizer_create();
	self->linker = linker_create(self->env);
	self->lexer = lexer_create(self->env, self->tokenizer, self->linker);
	self->minishell = minishell_create(envp);
	self->builtins = builtins_create(self->env);
	return (self);
}

bool shell_run(t_shell *shell)
{
	char     *line;
	t_vector *token_vector;

	line = input_get(shell->input);
	if (!line)
		return (false);
	print("%s\n", line);
	token_vector = tokenizer_tokenize(shell->tokenizer, line, " \n\'\"");
	token_vector = lexer_lex(shell->lexer, token_vector);
	// dbg_shell_print_verbose(shell);
	from_token_vector_to_token_list(shell, shell->minishell, token_vector);
	// quoter(shell->minishell);
	guesser(shell->minishell);
	// display_parsing_info(shell->minishell);
	set_token_Array(shell->minishell);
	fill_cmd_table(shell->minishell);
	parent_process(shell->minishell);
	minishell_clear(shell->minishell);
	shell->is_dirty = true;
	return (true);
}

bool shell_clear(t_shell *shell)
{
	prompt_clear(shell->prompt);
	input_clear(shell->input);
	tokenizer_clear(shell->tokenizer);
	lexer_clear(shell->lexer);
	linker_clear(shell->linker);
	shell->is_dirty = false;
	return (true);
}

t_shell *shell_destroy(t_shell *self)
{
	if (self)
	{
		if (self->env)
			environment_destroy(self->env);
		if (self->prompt)
			prompt_destroy(self->prompt);
		if (self->input)
			input_destroy(self->input);
		if (self->tokenizer)
			tokenizer_destroy(self->tokenizer);
		if (self->lexer)
			lexer_destroy(self->lexer);
		if (self->linker)
			linker_destroy(self->linker);
		if (self->minishell)
			minishell_destroy(self->minishell);
		if (self->builtins)
			builtins_destroy(self->builtins);
		memory_dealloc(self);
	}
	return (NULL);
}
