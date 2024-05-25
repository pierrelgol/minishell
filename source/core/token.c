/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_token *token_create(t_allocator *allocator)
{
	t_token *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	self->kind = KIND_NO_KIND;
	self->str = 0;
	self->len = 0;
	self->extra = 0;
	assert(self != NULL);
	return (self);
}

void token_init(t_allocator *allocator, t_token *self, char *str)
{
	assert(allocator != NULL);
	assert(self != NULL);
	self->str = string_clone(allocator, str);
	self->len = string_length(str);
}

void token_deinit(t_allocator *allocator, t_token *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	self->kind = KIND_NO_KIND;
	self->len = 0;
	if (self->extra)
		token_payload_destroy(allocator, (t_token_payload *) self->extra);
	self->extra = 0;
	allocator->destroy(allocator, self->str);
}

void     token_print(t_token *self)
{
	if (self)
		print(1,"%s",self->str);
}

void     token_print_kind(t_token *self)
{
	if (self->kind == KIND_NO_KIND)
		print(1, "[..]");
	if (self->kind == KIND_MAYBE_PATH)
		print(1, "[P?]");
	if (self->kind == KIND_OK_PATH)
		print(1, "[PO]");
	if (self->kind == KIND_ERR_PATH)
		print(1, "[PX]");
	if (self->kind == KIND_MAYBE_CMD)
		print(1, "[C?]");
	if (self->kind == KIND_OK_CMD)
		print(1, "[CO]");
	if (self->kind == KIND_ERR_CMD)
		print(1, "[CX]");
	if (self->kind == KIND_MAYBE_FILE)
		print(1, "[F?]");
	if (self->kind == KIND_OK_FILE)
		print(1, "[FO]");
	if (self->kind == KIND_ERR_FILE)
		print(1, "[FX]");
	if (self->kind == KIND_MAYBE_BLTN)
		print(1, "[B?]");
	if (self->kind == KIND_OK_BLTN)
		print(1, "[BO]");
	if (self->kind == KIND_ERR_BLTN)
		print(1, "[BX]");
	if (self->kind == KIND_APPEND)
		print(1, "[>>]");
	if (self->kind == KIND_HEREDOC)
		print(1, "[<<]");
	if (self->kind == KIND_ERR)
		print(1, "[ER]");
	if (self->kind == KIND_TILDE)
		print(1, "[~]");
	if (self->kind == KIND_AT)
		print(1, "[@]");
	if (self->kind == KIND_NOT)
		print(1, "[!]");
	if (self->kind == KIND_HASH)
		print(1, "[#]");
	if (self->kind == KIND_DOLLAR)
		print(1, "[$]");
	if (self->kind == KIND_MODULO)
		print(1, "[%]");
	if (self->kind == KIND_CARET)
		print(1, "[^]");
	if (self->kind == KIND_AND)
		print(1, "[&]");
	if (self->kind == KIND_STAR)
		print(1, "[*]");
	if (self->kind == KIND_OPAR)
		print(1, "[(]");
	if (self->kind == KIND_CPAR)
		print(1, "[)]");
	if (self->kind == KIND_DASH)
		print(1, "[_]");
	if (self->kind == KIND_PLUS)
		print(1, "[+]");
	if (self->kind == KIND_MINUS)
		print(1, "[-]");
	if (self->kind == KIND_EQL)
		print(1, "[=]");
	if (self->kind == KIND_OBRACK)
		print(1, "[[]");
	if (self->kind == KIND_CBRACK)
		print(1, "[]]");
	if (self->kind == KIND_OCURL)
		print(1, "[{]");
	if (self->kind == KIND_CBRACK)
		print(1, "[}]");
	if (self->kind == KIND_OR)
		print(1, "[|]");
	if (self->kind == KIND_SLASH)
		print(1, "[\\]");
	if (self->kind == KIND_BACKSLASH)
		print(1, "[/]");
	if (self->kind == KIND_QMARK)
		print(1, "[?]");
	if (self->kind == KIND_SCOLON)
		print(1, "[;]");
	if (self->kind == KIND_COLON)
		print(1, "[:]");
	if (self->kind == KIND_DQUOTE)
		print(1, "[\"]");
	if (self->kind == KIND_QUOTES)
		print(1, "[\']");
	if (self->kind == KIND_DOT)
		print(1, "[.]");
	if (self->kind == KIND_COMMA)
		print(1, "[,]");
	if (self->kind == KIND_RRDIR)
		print(1, "[>]");
	if (self->kind == KIND_LRDIR)
		print(1, "[<]");
	if (self->kind == KIND_SPC)
		print(1, "[ ]");
	print(1, "");
}

t_token *token_destroy(t_allocator *allocator, t_token *self)
{
	assert(self != NULL);
	assert(allocator != NULL);
	allocator->destroy(allocator, self);
	return (NULL);
}
