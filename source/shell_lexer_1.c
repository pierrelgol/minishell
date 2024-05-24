/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:26:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 12:26:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_shell_lexer *shell_lexer_create(t_allocator *allocator, t_token_iter *iter)
{
	t_shell_lexer *lexer;

	lexer = allocator->create(allocator, sizeof(t_shell_lexer));
	if (!lexer)
		return (NULL);
	lexer->allocator = allocator;
	lexer->output = iter;
	return (lexer);
}

t_token_iter *lexer_lex(t_shell_lexer *lexer)
{
	t_token_iter *iter;
	t_token      *token;

	iter = lexer->output;
	while (!iter_is_eof(iter))
	{
		token = iter_peek_curr(iter);
		if (!token)
			break;
		token_print(token);
		iter_eat(iter, 1);
	}
	iter_reset_start(lexer->output);
	return (lexer->output);
}

void lexer_clear(t_shell_lexer *lexer)
{
	(void)lexer;
}

t_shell_lexer *shell_lexer_destroy(t_shell_lexer *lexer)
{
	t_allocator *allocator;

	if (!lexer)
		return (NULL);
	allocator = lexer->allocator;
	allocator->destroy(allocator, lexer);
	return (NULL);
}
