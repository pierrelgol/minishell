/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_analyzer_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:45:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 15:45:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void lexer_identify_all_variables(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (token->ptr[0] == '$')
			{
				token->kind = KIND_VAR;
				token_set_str(token, enviroment_get(self->env, &token->ptr[1]));
				
			}
		}
		(void) token;
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_identifiers(t_lexer *self, t_vector *it)
{
	t_token *token;
	uint64_t i;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			i = 0;
			while (i < token->len)
			{
				if (!is_ascii(token->ptr[i]))
					break;
				i += 1;
			}
			if (i == token->len)
				token->kind = KIND_ID;
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_keywords(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && token->kind == KIND_ID)
		{
			//@TODO
			(void) token;
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_paths(t_lexer *self, t_vector *it)
{
	t_token *token;
	char	*path;

	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && (token->kind == KIND_NO_KIND || token->kind == KIND_ID))
		{
			path = linker_resolve(self->linker, token->ptr, 'f');
			if (path)
			{
				token_set_extra(token, (uintptr_t)path);
				token_set_kind(token, KIND_PATH);
			}
			else if (string_index_of(token->ptr, '/') != -1)
				token->kind = KIND_PATH;
			path = NULL;
			
		}
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_files(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		if (token && (token->kind == KIND_NO_KIND || token->kind == KIND_ID))
		{
			if (string_index_of(token->ptr, '.') != -1 || linker_resolve_path(self->linker, token->ptr))
				token->kind = KIND_FILE;
		}
		it_advance(it);
	}
	it_restore(it);
}
