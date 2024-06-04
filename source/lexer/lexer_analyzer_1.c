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

	(void)self;
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

void lexer_identify_all_builtins(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void)self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		(void)token;
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_variables(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void)self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		(void)token;
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_commands(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void)self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		(void)token;
		it_advance(it);
	}
	it_restore(it);
}

void lexer_identify_all_terminals(t_lexer *self, t_vector *it)
{
	t_token *token;

	(void)self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peek_curr(it);
		(void)token;
		it_advance(it);
	}
	it_restore(it);
}
