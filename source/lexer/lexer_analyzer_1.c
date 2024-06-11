/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analyzer_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:45:09 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 15:45:09 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void lexer_identify_all_whitespaces(t_lexer *self, t_vector *it)
{
	t_token *token;
	uint64_t i;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->len == 1)
		{
			i = 0;
			while (i < token->len)
			{
				if (!is_space(token->ptr[i]))
					break;
				i += 1;
			}
			if (i == token->len)
				token_set_kind(token, KIND_SPC);
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_quotes(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (token->ptr[0] == '\"')
				token->kind = KIND_DQUOTE;
			if (token->ptr[0] == '\'')
				token->kind = KIND_QUOTE;
		}
		(void) token;
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_redirect(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (string_ncompare(token->ptr, "<<", 2) == 0)
				token_set_kind(token, KIND_HERE_DOC);
			if (string_ncompare(token->ptr, ">>", 2) == 0)
				token_set_kind(token, KIND_APPEND);
			if (string_ncompare(token->ptr, "<", 1) == 0)
				token_set_kind(token, KIND_LRDIR);
			if (string_ncompare(token->ptr, ">", 1) == 0)
				token_set_kind(token, KIND_RRDIR);
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_boolean(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (string_ncompare(token->ptr, "&&", 2) == 0)
				token->kind = KIND_AND;
			if (string_ncompare(token->ptr, "||", 2) == 0)
				token->kind = KIND_OR;
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_terminals(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (token->len == 1 && token->ptr[0] == '|')
				token->kind = KIND_PIPE;
			else if (token->len == 1 && token->ptr[0] == '&')
				token->kind = KIND_AMPERSAND;
			else if (token->len == 1 && token->ptr[0] == ';')
				token->kind = KIND_SCOLON;
		}
		(void) token;
		it_advance(it);
	}
	it_restore(it);
}
