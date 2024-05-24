/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:34:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:34:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_token *iter_match_str(t_token_iter *iter, char *str)
{
	t_token *token;

	if (iter_is_eof(iter))
		return (NULL);
	token = iter_peek_next(iter);
	if (!token)
		return (NULL);
	if (token_is_eql_str(token, str))
		return (token);
	return (NULL);
}

uint64_t      iter_skip_kind(t_token_iter *iter, t_token_kind kind)
{
	uint64_t	count;

	count = 0;
	while (iter_match_kind(iter, kind) != NULL)
	{
		iter_eat(iter, 1);
		++count;
	}
	return (count);
}

uint64_t      iter_skip_str(t_token_iter *iter, char *str)
{
	uint64_t	count;

	count = 0;
	while (iter_match_str(iter, str) != NULL)
	{
		iter_eat(iter, 1);
		++count;
	}
	return (count);
}

t_token      *iter_peek_next(t_token_iter *iter)
{
	if (iter->index + 1 > iter->count)
		return (NULL);
	return ((t_token*)vector_peek_at(iter->tokens, iter->index + 1));
}

t_token      *iter_peek_curr(t_token_iter *iter)
{
	if (iter->index > iter->count)
		return (NULL);
	return ((t_token*)vector_peek_at(iter->tokens, iter->index));
}

