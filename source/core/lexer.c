/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_lexer *shell_lexer_create(t_allocator *allocator)
{
	t_shell_lexer *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->buffer = token_buffer_create(allocator);
	self->tokenized = NULL;
	assert(self->buffer != NULL);
	return (self);
}

void shell_lexer_init(t_allocator *allocator, t_shell_lexer *self, char **tokenized)
{
	assert(allocator != NULL);
	assert(self != NULL);
	token_buffer_init(allocator, self->buffer, tokenized);
	shell_lexer_lex(allocator, self);

	if (DEBUG == 1)
	{
		print(1, "\nshell_lexer_init()\n");
		buffer_print(self->buffer);
		print(1, "\nshell_lexer()\n");
	}
}
void shell_lexer_lex(t_allocator *allocator, t_shell_lexer *self)
{
	t_token_buffer *buffer;
	t_token        *temp;
	t_token        *curr;
	uint64_t        i;

	buffer = self->buffer;
	i = 0;
	buffer->index = 0;
	print(1,"\nshell_lexer_lex() START\n");
	while (token_buffer_end_of_buffer(buffer, i))
	{
		curr = token_buffer_peek_curr(buffer);
		if (curr->len == 1)
		{
			switch (curr->str[0])
			{
			case ' ':
				curr->kind = KIND_SPC;
				break;
			case '~':
				curr->kind = KIND_TILDE;
				break;
			case '@':
				curr->kind = KIND_AT;
				break;
			case '!':
				curr->kind = KIND_NOT;
				break;
			case '#':
				curr->kind = KIND_HASH;
				break;
			case '$':
				curr->kind = KIND_DOLLAR;
				break;
			case '%':
				curr->kind = KIND_MODULO;
				break;
			case '^':
				curr->kind = KIND_CARET;
				break;
			case '&':
				curr->kind = KIND_AND;
				break;
			case '*':
				curr->kind = KIND_STAR;
				break;
			case '(':
				curr->kind = KIND_OPAR;
				break;
			case ')':
				curr->kind = KIND_CPAR;
				break;
			case '-':
				curr->kind = KIND_DASH;
				break;
			case '+':
				curr->kind = KIND_PLUS;
				break;
			case '=':
				curr->kind = KIND_EQL;
				break;
			case '[':
				curr->kind = KIND_OBRACK;
				break;
			case ']':
				curr->kind = KIND_CBRACK;
				break;
			case '{':
				curr->kind = KIND_OCURL;
				break;
			case '}':
				curr->kind = KIND_CCURL;
				break;
			case '|':
				curr->kind = KIND_OR;
				break;
			case '/':
				curr->kind = KIND_SLASH;
				break;
			case '\\':
				curr->kind = KIND_BACKSLASH;
				break;
			case '?':
				curr->kind = KIND_QMARK;
				break;
			case ';':
				curr->kind = KIND_SCOLON;
				break;
			case ':':
				curr->kind = KIND_COLON;
				break;
			case '\"':
				curr->kind = KIND_DQUOTE;
				break;
			case '\'':
				curr->kind = KIND_QUOTES;
				break;
			case '.':
				curr->kind = KIND_DOT;
				break;
			case ',':
				curr->kind = KIND_COMMA;
				break;
			case '>':
				curr->kind = KIND_RRDIR;
				break;
			case '<':
				curr->kind = KIND_LRDIR;
				break;
			default:
				curr->kind = KIND_NO_KIND;
				break;
			}
			token_print_kind(curr);
		}

		if (curr->kind == KIND_LRDIR && token_buffer_peek_next(buffer)->str[0] == '<')
		{
			token_buffer_kill(buffer, 2);
			temp = token_create(allocator);
			token_init(allocator, temp, "<<");
			temp->kind = KIND_HEREDOC;
			token_print_kind(curr);
			curr = token_buffer_peek_curr(buffer);
			token_buffer_insert_at(buffer, temp, buffer->index);
		}
		if (curr->kind == KIND_RRDIR && token_buffer_peek_next(buffer)->str[0] == '>')
		{
			token_buffer_kill(buffer, 2);
			temp = token_create(allocator);
			token_init(allocator, temp, ">>");
			temp->kind = KIND_APPEND;
			curr = token_buffer_peek_curr(buffer);
			token_print_kind(curr);
			token_buffer_insert_at(buffer, temp, buffer->index);
		}
		token_buffer_eats(buffer, 1);
	}
	print(1,"\nshell_lexer_lex() END\n");
}

t_token_buffer *shell_lexer_get(t_shell_lexer *self)
{
	return (self->buffer);
}

void shell_lexer_deinit(t_allocator *allocator, t_shell_lexer *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	self->tokenized = NULL;
	token_buffer_deinit(allocator, self->buffer);
}

t_shell_lexer *shell_lexer_destroy(t_allocator *allocator, t_shell_lexer *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	allocator->destroy(allocator, self);
	return (NULL);
}
