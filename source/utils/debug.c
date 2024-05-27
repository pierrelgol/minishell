/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:32:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:32:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char *direct_io(t_shell *shell)
{
	static int i = 1;

	if (i < shell->argc)
		return (shell->argv[i++]);
	return (NULL);
}

char *getkind(t_token_kind kind)
{
	switch (kind)
	{
	case KIND_NO_KIND:
		return "NO_KIND";
	case KIND_SPC:
		return "SPC";
	case KIND_QUOTE_START:
		return "QUOTE_START";
	case KIND_QUOTE_END:
		return "QUOTE_END";
	case KIND_DQUOTE_START:
		return "DQUOTE_START";
	case KIND_DQUOTE_END:
		return "DQUOTE_END";
	case KIND_ASSIGNMENT:
		return "KIND_ASSIGNMENT";
	case KIND_RED_HERE_DOC:
		return "HERE_DOC";
	case KIND_ID:
		return "ID";
	case KIND_VAR:
		return "VAR";
	case KIND_KW:
		return "KW";
	case KIND_PIPE:
		return "PIPE";
	case KIND_RED_IN:
		return "RED_IN";
	case KIND_RED_OUT:
		return "RED_OUT";
	case KIND_RED_APPEND:
		return "RED_APPEND";
	case KIND_SCOLON:
		return "SCOLON";
	case KIND_AND:
		return "AND";
	case KIND_OR:
		return "OR";
	case KIND_FILE:
		return "FILE";
	case KIND_PATH:
		return "PATH";
	case KIND_BUILTIN:
		return "BUILTIN";
	case KIND_ARG:
		return "ARG";
	default:
		return "UNKNOWN";
	}
}
