/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:27:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/07 12:27:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_parser *parser_create(t_environment *env, t_lexer *lexer, t_linker *linker)
{
	t_parser *self;

	self = memory_alloc(sizeof(t_parser));
	if (!self)
		return (NULL);
	self->env = env;
	self->lexer = lexer;
	self->linker = linker;
	self->input = NULL;
	self->output = NULL;
	self->is_dirty = false;
	return (self);
}

t_vector *parser_parse(t_parser *self, t_vector *input)
{
	self->input = input;
	// where you put the logic
	return (self->output);
}

t_parser *parser_clear(t_parser *self)
{
	if (!self->is_dirty)
		return (self);
	// where you cleanup
	return (self);
}

t_parser *parser_destroy(t_parser *self)
{
	if (self->is_dirty)
		parser_clear(self);
	memory_dealloc(self);
	return (NULL);
}
