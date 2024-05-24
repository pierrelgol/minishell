/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:34:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:34:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_token_iter *iter_create(t_allocator *allocator, t_vector *tokens)
{
	t_token_iter *iter;

	iter = allocator->create(allocator, sizeof(t_token_iter));
	if (!iter)
		return (NULL);
	iter->allocator = allocator;
	iter->capacity = MAX_TOKENS;
	iter->count = 0;
	iter->index = 0;
	iter->tokens = tokens;
	iter_update_count(iter);
	return (iter);
}
t_token_iter *iter_create(t_allocator *allocator, t_vector *tokens)
{
	t_token_iter *iter;

	iter = allocator->create(allocator, sizeof(t_token_iter));
	if (!iter)
		return (NULL);
	iter->allocator = allocator;
	iter->capacity = MAX_TOKENS;
	iter->count = 0;
	iter->index = 0;
	iter->tokens = tokens;
	iter_update_count(iter);
	return (iter);
}
t_token_iter *iter_create(t_allocator *allocator, t_vector *tokens)
{
	t_token_iter *iter;

	iter = allocator->create(allocator, sizeof(t_token_iter));
	if (!iter)
		return (NULL);
	iter->allocator = allocator;
	iter->capacity = MAX_TOKENS;
	iter->count = 0;
	iter->index = 0;
	iter->tokens = tokens;
	iter_update_count(iter);
	return (iter);
}
t_token_iter *iter_create(t_allocator *allocator, t_vector *tokens)
{
	t_token_iter *iter;

	iter = allocator->create(allocator, sizeof(t_token_iter));
	if (!iter)
		return (NULL);
	iter->allocator = allocator;
	iter->capacity = MAX_TOKENS;
	iter->count = 0;
	iter->index = 0;
	iter->tokens = tokens;
	iter_update_count(iter);
	return (iter);
}

void iter_update_count(t_token_iter *iter)
{
	uint64_t	i;
	t_token	*token;

	i = 0;
	while (i < iter->capacity)
	{
		token = (t_token *)vector_peek_at(iter->tokens, i);
		if (token_is_kind(token, KIND_END_OF_TOK))
			break;
		++i;
	}
	iter->count = i;
}

void iter_reset_start(t_token_iter *iter)
{
	iter->index = 0;
	iter_update_count(iter);
	print(1, "iter->count = %d\n",iter->count);
	print(1, "iter->index = %d\n",iter->index);
}

uint64_t iter_eat(t_token_iter *iter, uint64_t n)
{
	if (iter->index + n > iter->count)
		return (0);
	iter->index += n;
	return (n);
}

t_token *iter_match_kind(t_token_iter *iter, t_token_kind kind)
{
	t_token *token;

	if (iter_is_eof(iter))
		return (NULL);
	token = iter_peek_next(iter);
	if (!token)
		return (NULL);
	if (token_is_kind(token, kind))
		return (token);
	return (NULL);
}

