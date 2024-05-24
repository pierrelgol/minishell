/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:43:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 09:43:43 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_vector *token_vector_create(t_allocator *allocator, uint64_t size)
{
	t_vector *vector;
	t_token  *token;
	uint64_t  i;

	vector = vector_create(allocator, size);
	if (!vector)
		return (NULL);
	i = 0;
	while (i < size)
	{
		token = token_create(allocator);
		if (!token)
			break;
		token->kind = KIND_NO_KIND;
		vector_insert_at(vector, (uintptr_t) token, i);
		++i;
	}
	token->kind = KIND_END_OF_TOK;
	return (vector);
}

t_vector *token_vector_clear(t_allocator *allocator, t_vector *vector)
{
	t_token *token;
	uint64_t i;

	i = 0;
	while (i < vector->count)
	{
		token = (t_token *) vector_peek_at(vector, i);
		token->kind = KIND_NO_KIND;
		token_clear(allocator, token);
		++i;
	}
	token->kind = KIND_END_OF_TOK;
	return (vector);
}

t_vector *token_vector_destroy(t_allocator *allocator, t_vector *vector)
{
	t_token *token;
	uint64_t i;

	i = 0;
	while (i < MAX_TOKENS)
	{
		token = (t_token *) vector_remove_at(vector, i);
		token_destroy(allocator, token);
		++i;
	}
	vector_destroy(vector);
	return (NULL);
}
