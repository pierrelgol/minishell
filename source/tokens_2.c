/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:33:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:33:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

bool     token_is_kind(t_token *token, t_token_kind kind)
{
	return (token->kind == kind);
}

bool     token_contains_scalar(t_token *t1, int32_t scalar)
{
	return (string_contains_scalar(t1->str, scalar, t1->len));
}

bool     token_contains_any(t_token *t1, t_bitset *any)
{
	return (string_contains_any(t1->str, any, t1->len));
}

bool     token_starts_with_scalar(t_token *t1, int32_t scalar)
{
	return (string_starts_with_scalar(t1->str, scalar));
}

bool     token_starts_with_any(t_token *t1, t_bitset *any)
{
	return (string_starts_with_any(t1->str, any));
}

