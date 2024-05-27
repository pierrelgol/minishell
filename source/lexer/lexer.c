/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:21:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 18:21:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void shell_lexer_lex(t_shell_lexer *self)
{
	shell_lexer_identify_whitespace(self, self->it);
	shell_lexer_identify_operators(self, self->it);
	shell_lexer_identify_builtins(self, self->it);
	shell_lexer_identify_id(self, self->it);
	shell_lexer_identify_path(self, self->it);
	shell_lexer_identify_file(self, self->it);
	shell_lexer_identify_keywords(self, self->it);
	shell_lexer_identify_quotes(self, self->it);
	shell_lexer_identify_assignment(self, self->it);
	// shell_lexer_kind_command(self, self->it);
}

void shell_lexer_identify_operators(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (token && string_compare(token->str, "<<") == 0)
				token->kind = KIND_RED_HERE_DOC;
			if (token && string_compare(token->str, "<<") == 0)
				token->kind = KIND_RED_HERE_DOC;
			else if (token && string_compare(token->str, ">>") == 0)
				token->kind = KIND_RED_APPEND;
			else if (token && string_compare(token->str, "||") == 0)
				token->kind = KIND_OR;
			else if (token && string_compare(token->str, "&&") == 0)
				token->kind = KIND_AND;
			else if (token && string_compare(token->str, "<") == 0)
				token->kind = KIND_RED_IN;
			else if (token && string_compare(token->str, ">") == 0)
				token->kind = KIND_RED_OUT;
			else if (token && string_compare(token->str, "|") == 0)
				token->kind = KIND_PIPE;
		}
		it_next(it);
	}
	it_restore(it);
}

void shell_lexer_identify_operator(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && string_is_all_predicate(token->str, is_whitespace))
			token->kind = KIND_SPC;
		it_next(it);
	}
	it_restore(it);
}

void shell_lexer_identify_whitespace(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && string_is_all_predicate(token->str, is_whitespace))
			token->kind = KIND_SPC;
		it_next(it);
	}
	it_restore(it);
}

void shell_lexer_identify_keywords(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;

	(void) self;
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (token && string_compare(token->str, "if") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "then") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "else") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "elif") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "fi") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "for") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "while") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "until") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "do") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "done") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "continu"
			                                             "e") == 0)
				token->kind = KIND_KW;
			else if (token && string_compare(token->str, "flemme "
			                                             "de faire "
			                                             "le "
			                                             "reste") == 0)
				token->kind = KIND_KW;
		}
		it_next(it);
	}
	it_restore(it);
}

void shell_lexer_identify_id(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;
	t_bitset set;

	set = bitset_init_from_str("_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP"
	                           "QRSTUVWXYZ");
	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (token->str[0] == '_' || is_alpha(token->str[0]))
			{
				if (string_is_all_any(&token->str[1], &set))
					token->kind = KIND_ID;

			}
			else if (token->str[0] == '$')
				token->kind = KIND_VAR;
		}
		it_next(it);
	}
	it_restore(it);
}

void shell_lexer_identify_builtins(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;

	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (string_compare("cd", token->str) == 0)
				token->kind = KIND_BUILTIN;
			if (string_compare("echo", token->str) == 0)
				token->kind = KIND_BUILTIN;
			if (string_compare("env", token->str) == 0)
				token->kind = KIND_BUILTIN;
			if (string_compare("export", token->str) == 0)
				token->kind = KIND_BUILTIN;
			if (string_compare("unset", token->str) == 0)
				token->kind = KIND_BUILTIN;
			if (string_compare("pwd", token->str) == 0)
				token->kind = KIND_BUILTIN;
		}
		it_next(it);
	}
	it_restore(it);
}

void shell_lexer_identify_path(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;

	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (is_path(token->str))
				token->kind = KIND_PATH;
		}
		it_next(it);
	}
	it_restore(it);
}

void shell_lexer_identify_file(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;

	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (is_file(token->str))
				token->kind = KIND_FILE;
		}
		it_next(it);
	}
	it_restore(it);
}

void shell_lexer_identify_quotes(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;

	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			if (string_starts_with_scalar(token->str, '\''))
				token->kind = KIND_QUOTE_START;
			else if (string_starts_with_scalar(token->str, '\"'))
				token->kind = KIND_DQUOTE_START;
			else if (string_ends_with_scalar(token->str, '\''))
				token->kind = KIND_QUOTE_END;
			else if (string_ends_with_scalar(token->str, '\"'))
				token->kind = KIND_DQUOTE_END;
		}
		it_next(it);
	}
	it_restore(it);
}

// void shell_lexer_identify_cmd(t_shell_lexer *self, t_iterator *it)
// {
// }

void shell_lexer_identify_assignment(t_shell_lexer *self, t_iterator *it)
{
	t_token *token;
	bool	start;
	bool	mid;
	bool	end;

	it_save(it);
	while (!it_end(it))
	{
		token = (t_token *) it_peekcurr(it);
		if (token && token->kind == KIND_NO_KIND)
		{
			start = string_starts_with_predicate(token->str, is_ascii);
			mid = string_contains_scalar(token->str, '=', 999);
			end  = string_ends_with_predicate(token->str, is_ascii);
			if (start && mid && end)
				token->kind = KIND_ASSIGNMENT;
		}
		it_next(it);
	}
	it_restore(it);
}
