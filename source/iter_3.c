/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:34:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 11:34:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_token      *iter_peek_prev(t_token_iter *iter)
{
	if (iter->index >= 1)
		return ((t_token*)vector_peek_at(iter->tokens, iter->index - 1));
	return (NULL);
}

bool          iter_is_eof(t_token_iter *iter)
{
	return (iter->index == iter->count);
}

t_token_iter *iter_destroy(t_token_iter *self)
{
	t_allocator	*allocator;

	if (!self)
		return (NULL);
	allocator = self->allocator;
	self->allocator = NULL;
	self->capacity = 0;
	self->count = 0;
	self->index = 0;
	allocator->destroy(allocator, self);
	return (NULL);
}
