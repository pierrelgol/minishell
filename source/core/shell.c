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

// This function will return a shell, and it will create
// every substructure that is needed for the shell to work
t_shell *shell_create(int32_t argc, char **argv, char **envp)
{
	t_shell *self;

	self = (t_shell *) memory_alloc(sizeof(t_shell));
	if (!self)
		return (NULL);
	self->argc = argc;
	self->argv = argv;
	self->envp = envp;
	// @STEP02 creating the environement variable hashmap
	// this will be used extensively in almost every places where we need
	// to get some variables from the environment
	self->env = environment_create(envp);
	// @STEOP03 this simple structure will handle everythin related to building the prompt
	// meaning it will go and fetch the $PWD and join it to build the prompt;
	self->prompt = prompt_create(self->env);
	// @STEOP04 this structure will be responsible for getting the input from our user
	// and it's one layer of abstraction that allow us to quickly switch between
	// -DDIRECT_IO=0 && -DIRECT_IO=1 which is how we can decide if you want to use
	// the shell with the fuzzer which uses argc/argv or with readline.
	self->input = input_create(self->env, self->prompt, argc, argv);
	// @STEP05 The tokenizer is the structure responsible for taking the inputs, and cutting in into
	// tokens which will be stored inside a vector (an array that growth automatically and is iterable)
	self->tokenizer = tokenizer_create();
	// @STEP06 The linker is responsible for providing support to every
	// structure that needs to be able to test and resolve paths.
	self->linker = linker_create(self->env);
	// @STEP07 The lexer is the structure responsible for identifying roughly the "type" of a token
	// given the current syntax, and contextx, it will take the tokenizer token_vector output
	// iterate over it and simply fill the token_kind field. It will also put inside the extra
	// field the path found by the linker for CMD kind.
	self->lexer = lexer_create(self->env, self->tokenizer, self->linker);
	// @STEP08 --> in ./source/main.c

	// @STEP08XXXXX this is where you add your stuff
	self->parser = parser_create(self->env, self->lexer, self->linker);
	self->exec = exec_create(self, self->env, self->linker);
	return (self);
}

bool shell_run(t_shell *shell)
{
	char     *line;
	t_vector *token_vector;

	// @STEP09 here we request the line that input got
	line = input_get(shell->input); // -> ./source/input/input.c
	if (!line)
		return (false);
	// @STEP15 if the lin is null we stop the loop and clean everything
	// by calling shell_destroy() in // -> ./source/main.c
	print("%s\n", line);
	// @STEP16 we call the tokenizer and pass it the current line as well
	// as our separator those will be kept in the split
	// --> ./source/tokenizer/tokenizer.c
	token_vector = tokenizer_tokenize(shell->tokenizer, line, " \n\'\"");
	// @STEP20 we now have a token_vector full of our split we pass it to
	// the lexer which will identify all of the types for our tokens
	// --> ./source/lexer/lexer.c
	token_vector = lexer_lex(shell->lexer, token_vector);
	// @STEP22 we now have a token vector where every token structure has
	// a 1: ptr --> with the string splited in the tokenizer
	// a 2: len --> with the length of the ptr field
	// a 3: kind --> with the kind found by the lexer
	// we can now print all of our debug information
	// you can also call dbg_shell_print_verbose(shell) if you want
	// some extra informations

	// @STEP22XXXXXX This is where you add your stuff
	token_vector = parser_parse(shell->parser, token_vector);
	token_vector = exec_execute(shell->exec, token_vector);

	// @STEP22XXXXX Add the debug info 
	dbg_shell_print(shell);

	shell->is_dirty = true;
	// @STEP23 back to --> ./source/main.c
	return (true);
}

bool shell_clear(t_shell *shell)
{
	prompt_clear(shell->prompt);
	input_clear(shell->input);
	tokenizer_clear(shell->tokenizer);
	lexer_clear(shell->lexer);
	linker_clear(shell->linker);
	parser_clear(shell->parser);
	exec_clear(shell->exec);
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
		if (self->parser)
			parser_destroy(self->parser);
		if (self->exec)
			exec_destroy(self->exec);
		memory_dealloc(self);
	}
	return (NULL);
}
