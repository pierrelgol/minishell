/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:02:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/06 11:02:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void dbg_shell_print(t_shell *shell)
{
	dbg_environment_print(shell->env);
	dbg_prompt_print(shell->prompt);
	dbg_input_print(shell->input);
	dbg_tokenizer_print(shell->tokenizer);
	dbg_lexer_print(shell->lexer);
}

void dbg_environment_print(t_environment *env)
{
	t_vector *it;
	char     *key;
	char     *val;
	uint64_t  i;

	print("--------------------------------\n");
	print("STEP : ENVIRONMENT\n\n");
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

void dbg_prompt_print(t_prompt *prompt)
{
	print("STEP : PROMPT\n\n");
	print("[%s]\n", prompt->prompt);
	print("--------------------------------\n");
}

void dbg_input_print(t_input *input)
{
	print("STEP : INPUT\n\n");
	print("[%s]\n", input->line);
	print("--------------------------------\n");
}

void dbg_tokenizer_print(t_tokenizer *tokenizer)
{
	t_vector *it;
	uint64_t  i;
	t_token  *token;

	print("STEP : TOKENIZER\n\n");
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

void dbg_token_print(t_token *token)
{
	if (token->kind == KIND_NO_KIND)
		print("NO_KIND\n");
	if (token->kind == KIND_ID)
		print("ID\n");
	if (token->kind == KIND_CMD)
		print("CMD\n");
	if (token->kind == KIND_SPC)
		print("SPC\n");
	if (token->kind == KIND_PATH)
		print("PATH\n");
	if (token->kind == KIND_FILE)
		print("FILE\n");
	if (token->kind == KIND_BLTN)
		print("BLTN\n");
	if (token->kind == KIND_ARG)
		print("ARG\n");
	if (token->kind == KIND_VAR)
		print("VAR\n");
	if (token->kind == KIND_ERR)
		print("ERR\n");
	if (token->kind == KIND_PIPE)
		print("PIPE\n");
	if (token->kind == KIND_AMPERSAND)
		print("AMPERSAND\n");
	if (token->kind == KIND_SCOLON)
		print("SCOLON\n");
	if (token->kind == KIND_RRDIR)
		print("RRDIR\n");
	if (token->kind == KIND_LRDIR)
		print("LRDIR\n");
	if (token->kind == KIND_HERE_DOC)
		print("HERE_DOC\n");
	if (token->kind == KIND_APPEND)
		print("APPEND\n");
	if (token->kind == KIND_QUOTE)
		print("QUOTE\n");
	if (token->kind == KIND_DQUOTE)
		print("DQUOTE\n");
	if (token->kind == KIND_ASSIGNMENT)
		print("ASSIGNMENT\n");
	if (token->kind == KIND_AND)
		print("AND\n");
	if (token->kind == KIND_OR)
		print("OR\n");
}

void dbg_lexer_print(t_lexer *lexer)
{
	t_vector *it = lexer->token_vector;
	t_token  *token;
	uint64_t  i;

	print("STEP : LEXER\n\n");
	i = 0;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		print("[%lu]", i);
		if (token)
			dbg_token_print(token);
		i += 1;
		it_advance(it);
	}
	it_restore(it);
	print("--------------------------------\n");
}
