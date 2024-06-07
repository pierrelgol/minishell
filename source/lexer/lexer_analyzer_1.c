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
// @STEP21 The basic structure is always the same we pass our vector_token to the
// function -----------------------------------------------------|
//                                                              \/
// void lexer_identify_all_whitespaces(t_lexer *self, t_vector *it)
// {
// 	t_token *token;
// 	uint64_t i;

// 	(void) self;
//  +-----> it_save(it); // @1 HERE WE SAVE THE CURRENT INDEX OF OUR VECTOR (aka 0)
//  |       while (!it_end(it)) // @2 WHILE it->index != it->count (which is the count of tokens in the token_vector)
//  |       {
//  |	        token = (t_token *) it_peek_curr(it); // @3 we look at the current token
//  |	        if (token && token->len == 1) // @4 if the token is not nul and insert (THE THING YOU NEED TO TEST TO INFER THE KIND OF TOKEN YOU ARE LOOKING AT)
//  |	        {
//  |		    i = 0;
//  |		    while (i < token->len)
//  |		    {
//  |			if (!is_space(token->ptr[i]))
//  |				break;
//  |			i += 1;
//  |		    }
//  |		    if (i == token->len) // @5 if the token did follow the syntactic rules than we can set the new kind
//  |                   token_set_kind(token, KIND_SPC);
//  |	        }
//  |	        it_advance(it); // @6 we consume the current token equivalent
//  |       }
//  |          // @7 we are done we went trhough every token in the token_vector
//  |         // we identified and updated every token kind to reflect that
//  |--> it_restore(it); // @8 now we restore the index to (@1)
// }
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
