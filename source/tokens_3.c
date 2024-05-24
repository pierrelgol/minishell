/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:33:57 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:33:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

bool token_ends_with_scalar(t_token *t1, int32_t scalar)
{
	return (string_ends_with_scalar(t1->str, scalar));
}

bool token_ends_with_any(t_token *t1, t_bitset *any)
{
	return (string_ends_with_any(t1->str, any));
}

bool token_is_eql_str(t_token *t1, char *str)
{
	return (string_compare(t1->str, str) == 0);
}

bool token_is_eql_len(t_token *t1, uint64_t len)
{
	return (t1->len == len);
}

bool token_is_eql_extra(t_token *t1, uint64_t extra, bool(t_cmp)(uintptr_t x1, uintptr_t x2))
{
	return (t_cmp(t1->extra, extra) == true);
}
