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

void lexer_identify_all_boolean(t_lexer *self, t_vector *it)
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

void lexer_identify_all_files(t_lexer *self, t_vector *it)
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

void lexer_identify_all_keywords(t_lexer *self, t_vector *it)
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

void lexer_identify_all_identifiers(t_lexer *self, t_vector *it)
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
