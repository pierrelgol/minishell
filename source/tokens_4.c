/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:44:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:44:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void token_print_kind(t_token_kind kind) {
    if (kind == KIND_NO_KIND) {
        print(1, "X");
    } else if (kind == KIND_WHITESPACE) {
        print(1, "_");
    } else if (kind == KIND_CMD_MAYBE_ARG) {
        print(1, "CMD");
    } else if (kind == KIND_KEYWORD) {
        print(1, "KW");
    } else if (kind == KIND_PATH) {
        print(1, "PATH");
    } else if (kind == KIND_FILE) {
        print(1, "FILE");
    } else if (kind == KIND_IDENTIFIER) {
        print(1, "ID");
    } else if (kind == KIND_SEMI_COLON) {
        print(1, ";");
    } else if (kind == KIND_BUILTIN_NO_ARG) {
        print(1, "BLT_W/0");
    } else if (kind == KIND_BUILTIN_ARG) {
        print(1, "BLT_W/A");
    } else if (kind == KIND_CMD_NO_ARG) {
        print(1, "CMD_W/0");
    } else if (kind == KIND_CMD_ARG) {
        print(1, "CMD_W/A");
    } else if (kind == KIND_ARG) {
        print(1, "ARG");
    } else if (kind == KIND_AND) {
        print(1, "AND");
    } else if (kind == KIND_OR) {
        print(1, "OR");
    } else if (kind == KIND_PIPE) {
        print(1, "PIPE");
    } else if (kind == KIND_LEFT_REDIR) {
        print(1, "LRDIR");
    } else if (kind == KIND_RIGHT_REDIR) {
        print(1, "RRDIR");
    } else if (kind == KIND_HEREDOC) {
        print(1, "HDOC");
    } else if (kind == KIND_APPEND) {
        print(1, "APPND");
    } else if (kind == KIND_BACKGROUND) {
        print(1, "BG");
    } else if (kind == KIND_SUBSHELL_START) {
        print(1, "SUBSH");
    } else if (kind == KIND_COMMENT) {
        print(1, "COMT");
    } else if (kind == KIND_ASSIGNMENT) {
        print(1, "ASIGN");
    } else if (kind == KIND_NEWLINE) {
        print(1, "NL");
    } else
        print(1, "?");
}
bool token_print(t_token *tok)
{
	if (!tok)
	{
		print(1, "(NULL)->");
		return (false);
	}
	else
	{
	    print(1,"[");
		token_print_kind(tok->kind);
	    print(1,"]->");
	    
	}
	return (true);
}

t_token *token_destroy(t_allocator *allocator, t_token *tok)
{
	if (!tok)
		return (NULL);
	allocator->destroy(allocator, tok->str);
	tok->extra = 0;
	tok->kind = KIND_NO_KIND;
	tok->str = NULL;
	tok->len = 0;
	allocator->destroy(allocator, tok);
	return (NULL);
}
