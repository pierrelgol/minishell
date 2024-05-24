/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:37:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 12:37:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_shell_parser *shell_parser_create(t_allocator *allocator, t_token_iter *iter)
{
	t_shell_parser *parser;

	parser = allocator->create(allocator, sizeof(t_shell_parser));
	if (!parser)
		return (NULL);
	parser->allocator = allocator;
	parser->output = iter;
	return (parser);
}

void parser_clear(t_shell_parser *parser)
{
	(void) parser;
}

t_shell_parser *shell_parser_destroy(t_shell_parser *parser)
{
	t_allocator *allocator;

	if (!parser)
		return (NULL);
	allocator = parser->allocator;
	allocator->destroy(allocator, parser);
	return (NULL);
}
