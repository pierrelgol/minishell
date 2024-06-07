/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:26:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/06 11:26:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void dbg_shell_print_verbose(t_shell *shell)
{
	print("--------------------------------\n");
	print("STEP : SHELL VERBOSE\n\n");
	print("shell->argc                       : [%d]\n", (int32_t) shell->argc);
	print("shell->argv                       : [%p]\n", shell->argv);
	print("shell->envp                       : [%p]\n", shell->envp);
	print("shell->env                        : [%p]\n", shell->env);
	print("shell->prompt                     : [%p]\n", shell->prompt);
	print("shell->input                      : [%p]\n", shell->input);
	print("shell->tokenizer                  : [%p]\n", shell->tokenizer);
	print("shell->lexer                      : [%p]\n", shell->lexer);
	print("shell->is_dirty                   : [%s]\n", shell->is_dirty == true ? "true" : "false");
	dbg_environment_print_verbose(shell->env);
	dbg_prompt_print_verbose(shell->prompt);
	dbg_input_print_verbose(shell->input);
	dbg_tokenizer_print_verbose(shell->tokenizer);
	dbg_lexer_print_verbose(shell->lexer);
	print("--------------------------------\n");
}

void dbg_environment_print_verbose(t_environment *env)
{
	t_vector *it;
	char     *key;
	char     *val;
	uint64_t  i;

	print("STEP : ENVIRONMENT VERBOSE\n\n");
	print("env->keys                       : [%p]\n", env->keys);
	print("env->keys->capacity             : [%lu]\n", env->keys->capacity);
	print("env->keys->count                : [%lu]\n", env->keys->count);
	print("env->keys->data                 : [%p]\n", env->keys->data);
	print("env->keys->index                : [%lu]\n", env->keys->index);
	print("env->keys->saved                : [%lu]\n", env->keys->saved);
	print("env->keys->is_sorted            : [%lu]\n", env->keys->is_sorted);
	print("env->vars                       : [%p]\n", env->vars);
	print("env->vars->capacity             : [%lu]\n", env->vars->capacity);
	print("env->vars->count                : [%lu]\n", env->vars->count);
	print("env->vars->bucket               : [%p]\n", env->vars->bucket);
	print("env->vars->bucket               : [%p]\n", env->vars->bucket);
	print("env->vars->bucket->capacity     : [%lu]\n", env->keys->capacity);
	print("env->vars->bucket->count        : [%lu]\n", env->keys->count);
	print("env->vars->bucket->data         : [%p]\n", env->keys->data);
	print("env->vars->bucket->index        : [%lu]\n", env->keys->index);
	print("env->vars->bucket->saved        : [%lu]\n", env->keys->saved);
	print("env->vars->bucket->is_sorted    : [%lu]\n", env->keys->is_sorted);
	print("env->is_dirty                   : [%s]\n", env->is_dirty == true ? "true" : "false");

	i = 0;
	it = env->keys;
	it_save(it);
	while (!it_end(it))
	{
		key = (char *) it_peek_curr(it);
		val = enviroment_get(env, key);
		print("[%lu]%s=%s\n", i, key, val);
		it_advance(it);
		i += 1;
	}
	it_restore(it);

	print("--------------------------------\n");
}

void dbg_prompt_print_verbose(t_prompt *prompt)
{
	print("STEP : PROMPT VERBOSE\n\n");
	print("prompt->env      : [%p]\n", prompt->env);
	print("prompt->prompt   : [%s]\n", prompt->prompt);
	print("prompt->is_dirty : [%s]\n", prompt->is_dirty == true ? "true" : "false");
	print("--------------------------------\n");
}

void dbg_input_print_verbose(t_input *input)
{
	print("STEP : INPUT VERBOSE\n\n");
	print("input->env       : [%p]\n", input->env);
	print("input->argc      : [%d]\n", (int32_t) input->argc);
	print("input->argv      : [%p]\n", input->argv);
	print("input->index     : [%d]\n", input->index);
	print("input->line      : [%s]\n", input->line);
	print("input->is_dirty  : [%s]\n", input->is_dirty == true ? "true" : "false");
	print("--------------------------------\n");
}

void dbg_tokenizer_print_verbose(t_tokenizer *tokenizer)
{
	t_vector *it;
	uint64_t  i;
	t_token  *token;

	print("STEP : TOKENIZER VERBOSE\n\n");
	print("tokenizer->input                      : [%s]\n", tokenizer->input);
	print("tokenizer->delim                      : [%s]\n", tokenizer->delim);
	print("tokenizer->output                     : [%p]\n", tokenizer->output);
	print("tokenizer->output->capacity           : [%lu]\n",
	      tokenizer->output->capacity);
	print("tokenizer->output->count              : [%lu]\n",
	      tokenizer->output->count);
	print("tokenizer->output->data               : [%p]\n",
	      tokenizer->output->data);
	print("tokenizer->output->index              : [%lu]\n",
	      tokenizer->output->index);
	print("tokenizer->output->saved              : [%lu]\n",
	      tokenizer->output->saved);
	print("tokenizer->output->is_sorted          : [%lu]\n",
	      tokenizer->output->is_sorted);
	print("tokenizer->is_dirty                   : [%s]\n", tokenizer->is_dirty == true ? "true" : "false");
	i = 0;
	it = tokenizer->output;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		print("[%lu]:[%s]\n", i, token->ptr);
		it_advance(it);
		i += 1;
	}
	it_restore(it);
	print("--------------------------------\n");
}

void dbg_token_print_verbose(t_token *token)
{
	printf("token : [%-24s][%3lu]",token->ptr,token->len);
	if (token->kind == KIND_NO_KIND)
		printf("[%-20s]","NO_KIND");
	if (token->kind == KIND_ID)
		printf("[%-20s]","IDENTIFER");
	if (token->kind == KIND_CMD)
		printf("[%-20s]","COMMAND");
	if (token->kind == KIND_SPC)
		printf("[%-20s]","SPACE");
	if (token->kind == KIND_PATH)
		printf("[%-20s]","PATH");
	if (token->kind == KIND_FILE)
		printf("[%-20s]","FILE");
	if (token->kind == KIND_BLTN)
		printf("[%-20s]","BUILTIN");
	if (token->kind == KIND_ARG)
		printf("[%-20s]","ARGUMENT");
	if (token->kind == KIND_VAR)
		printf("[%-20s]","VARIABLE");
	if (token->kind == KIND_ERR)
		printf("[%-20s]","ERROR");
	if (token->kind == KIND_PIPE)
		printf("[%-20s]","PIPE");
	if (token->kind == KIND_AMPERSAND)
		printf("[%-20s]","AMPERSAND");
	if (token->kind == KIND_SCOLON)
		printf("[%-20s]","SEMI_COLON");
	if (token->kind == KIND_RRDIR)
		printf("[%-20s]","RIGHT REDIRECTION");
	if (token->kind == KIND_LRDIR)
		printf("[%-20s]","LEFT REDIRECTION");
	if (token->kind == KIND_HERE_DOC)
		printf("[%-20s]","HERE DOC");
	if (token->kind == KIND_APPEND)
		printf("[%20s]","APPEND");
	if (token->kind == KIND_QUOTE)
		printf("[%-20s]", "QUOTE");
	if (token->kind == KIND_DQUOTE)
		printf("[%-20s]","DQUOTE");
	if (token->kind == KIND_ASSIGNMENT)
		printf("[%-20s]","ASSIGNMENT");
	if (token->kind == KIND_AND)
		printf("[%-20s]\n","AND");
	if (token->kind == KIND_OR)
		printf("[%-20s]\n","OR");


	printf("addr : [%16p]\n",token);
}

void dbg_lexer_print_verbose(t_lexer *lexer)
{
	t_vector *it = lexer->token_vector;
	t_token  *token;
	uint64_t  i;

	print("STEP : LEXER VERBOSE\n\n");
	print("lexer->env                        : [%p]\n", lexer->env);
	print("lexer->token_vector               : [%p]\n", lexer->token_vector);
	print("lexer->token_vector->capacity     : [%lu]\n", lexer->token_vector->capacity);
	print("lexer->token_vector->count        : [%lu]\n", lexer->token_vector->count);
	print("lexer->token_vector->data         : [%p]\n", lexer->token_vector->data);
	print("lexer->token_vector->index        : [%lu]\n", lexer->token_vector->index);
	print("lexer->token_vector->saved        : [%lu]\n", lexer->token_vector->saved);
	print("lexer->token_vector->is_sorted    : [%lu]\n", lexer->token_vector->is_sorted);
	print("lexer->tokenizer                  : [%p]\n", lexer->tokenizer);
	print("lexer->is_dirty                   : [%s]\n", lexer->is_dirty == true ? "true" : "false");
	i = 0;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		printf("[%3lu]", i);
		fflush(stdout);
		if (token)
			dbg_token_print_verbose(token);
		i += 1;
		it_advance(it);
	}
	it_restore(it);
}
