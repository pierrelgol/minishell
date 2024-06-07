/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analyzer_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:45:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 15:45:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void lexer_identify_all_commands(t_lexer *self, t_vector *it)
{
	t_token *token;
	char    *path;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_ID)
		{
			path = linker_resolve(self->linker, token->ptr, 'x');
			if (path)
			{
				token_set_extra(token, (uintptr_t) path);
				token_set_kind(token, KIND_CMD);
				path = NULL;
			}
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_assignments(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (string_index_of(token->ptr, '=') != -1)
				token->kind = KIND_ASSIGNMENT;
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_builtins(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && (token->kind == KIND_NO_KIND ||token->kind == KIND_ID))
		{
			if (string_compare("echo", token->ptr) == 0)
				token->kind = KIND_BLTN;
			if (string_compare("cd", token->ptr) == 0)
				token->kind = KIND_BLTN;
			if (string_compare("env", token->ptr) == 0)
				token->kind = KIND_BLTN;
			if (string_compare("export", token->ptr) == 0)
				token->kind = KIND_BLTN;
			if (string_compare("unset", token->ptr) == 0)
				token->kind = KIND_BLTN;
		}
		(void) token;
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_arguments(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && (token->kind == KIND_NO_KIND || token->kind == KIND_ID))
		{
			if (token->len >= 2 && token->ptr[0] == '-')
				token->kind = KIND_ARG;
			if (( token->len >= 3 && token->ptr[0] == '-' && token->ptr[1] == '-'))
				token->kind = KIND_ARG;
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_operators(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		(void) token;
		it_advance(it);
	}
	it_restore(it);
}
