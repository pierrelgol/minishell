/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:32:08 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 15:32:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_lexer *lexer_create(t_environment *env, t_tokenizer *tokenizer, t_linker *linker)
{
	t_lexer *self;

	self = memory_alloc(sizeof(t_lexer));
	if (!self)
		return (NULL);
	self->env = env;
	self->linker = linker;
	self->tokenizer = tokenizer;
	self->token_vector = NULL;
	self->is_dirty = false;
	return (self);
}

t_vector *lexer_lex(t_lexer *self, t_vector *input)
{
	(void) self;
	self->token_vector = input;

	// every function here follows the same structure
	// goto --> ./source/lexer/lexer_analyzer1.c to see more in depth
	// explaination in @STEP21
	lexer_identify_all_whitespaces(self, input);
	lexer_identify_all_quotes(self, input);
	lexer_identify_all_redirect(self, input);
	lexer_identify_all_boolean(self, input);
	lexer_identify_all_terminals(self, input);

	lexer_identify_all_variables(self, input);
	lexer_identify_all_identifiers(self, input);
	lexer_identify_all_keywords(self, input);
	lexer_identify_all_files(self, input);
	lexer_identify_all_builtins(self, input);

	lexer_identify_all_commands(self, input);
	lexer_identify_all_paths(self, input);
	lexer_identify_all_assignments(self, input);
	lexer_identify_all_arguments(self, input);
	lexer_identify_all_operators(self, input);

	self->is_dirty = true;
	// @STEP22
	// back to ./source/core/shell.c
	return (input);
}

t_lexer *lexer_clear(t_lexer *self)
{
	(void) self;
	self->is_dirty = false;
	return (self);
}

t_lexer *lexer_destroy(t_lexer *self)
{
	if (self->is_dirty)
		lexer_clear(self);
	memory_dealloc(self);
	return (NULL);
}
