/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_token_buffer *token_buffer_create(t_allocator *allocator)
{
	t_token_buffer *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->count = 0;
	self->index = 0;
	self->tokens = vector_create(allocator);
	assert(self->tokens != NULL);
	return (self);
}

void token_buffer_init(t_allocator *allocator, t_token_buffer *self, char **tokenized)
{
	t_token *token;
	uint64_t i;

	assert(allocator != NULL);
	assert(self != NULL);
	assert(tokenized != NULL);
	i = 0;
	while (tokenized[i])
	{
		token = token_create(allocator);
		token_init(allocator, token, tokenized[i]);
		token_buffer_push(self, token);
		++i;
	}
}

bool token_buffer_insert_at(t_token_buffer *self, t_token *token, uint64_t index)
{
	if (vector_insert_at(self->tokens, (uintptr_t) token, index))
	{
		self->count += 1;
		return (true);
	}
	return (false);
}

t_token *token_buffer_remove_at(t_token_buffer *self, uint64_t index)
{
	t_token *token;

	if (vector_is_empty(self->tokens))
		return (NULL);
	token = (t_token *) vector_peek_at(self->tokens, index);
	if (vector_remove_at(self->tokens, index))
	{
		self->count -= 1;
		return (token);
	}
	return (NULL);
}

void token_buffer_push(t_token_buffer *self, t_token *token)
{
	token_buffer_insert_at(self, token, self->count);
}

t_token *token_buffer_pop(t_token_buffer *self)
{
	if (token_buffer_is_empty(self))
		return (NULL);
	return (token_buffer_remove_at(self, self->count - 1));
}

t_token *token_buffer_get_at(t_token_buffer *self, uint64_t index)
{
	if (token_buffer_end_of_buffer(self, index))
		return (NULL);
	return ((t_token *) vector_peek_at(self->tokens, index));
}

bool token_buffer_is_empty(t_token_buffer *self)
{
	return (self->count == 0);
}

uint64_t token_buffer_kill(t_token_buffer *self, uint64_t n)
{
	t_token *token;
	uint64_t count;
	uint64_t i;

	i = token_buffer_get_curr_index(self);
	count = 0;
	while (count < n)
	{
		if (token_buffer_is_empty(self))
			return (count);
		token = token_buffer_remove_at(self, i);
		token_destroy(self->allocator, token);
		++count;
	}
	return (count);
}

uint64_t token_buffer_eats(t_token_buffer *self, uint64_t n)
{
	if (token_buffer_end_of_buffer(self, self->index + n))
		return (0);
	self->index += n;
	return (n);
}

uint64_t token_buffer_skip_kind(t_token_buffer *self, t_token_kind kind)
{
	uint64_t skipped;

	if (token_buffer_is_empty(self))
		return (0);
	skipped = 0;
	while (token_buffer_match_kind(self, kind, 1))
	{
		token_buffer_eats(self, 1);
		++skipped;
	}
	return (skipped);
}

uint64_t token_buffer_skip_string(t_token_buffer *self, char *str)
{
	uint64_t skipped;

	if (token_buffer_is_empty(self))
		return (0);
	skipped = 0;
	while (token_buffer_match_string(self, str, 1))
	{
		token_buffer_eats(self, 1);
		++skipped;
	}
	return (skipped);
}

t_token *token_buffer_match_kind(t_token_buffer *self, t_token_kind kind, uint64_t n)
{
	t_token *next_token;
	uint64_t i;

	if (token_buffer_is_empty(self))
		return (NULL);
	i = 0;
	while (i < n && token_buffer_end_of_buffer(self, self->index + i))
	{
		next_token = token_buffer_get_at(self, self->index + i);
		if (next_token && next_token->kind != kind)
			return (NULL);
		++i;
	}
	return (next_token);
}

t_token *token_buffer_match_string(t_token_buffer *self, char *str, uint64_t n)
{
	t_token *next_token;
	uint64_t i;

	if (token_buffer_is_empty(self))
		return (NULL);
	i = 0;
	while (i < n && token_buffer_end_of_buffer(self, self->index + i))
	{
		next_token = token_buffer_get_at(self, self->index + i);
		if (next_token && string_compare(next_token->str, str) != 0)
			return (NULL);
		++i;
	}
	return (next_token);
}

t_token *token_buffer_peek_curr(t_token_buffer *self)
{
	if (token_buffer_is_empty(self) || token_buffer_end_of_buffer(self, self->index))
		return (NULL);
	return (token_buffer_get_at(self, self->index));
}

t_token *token_buffer_peek_next(t_token_buffer *self)
{
	if (token_buffer_is_empty(self) || token_buffer_end_of_buffer(self, self->index + 1))
		return (NULL);
	return (token_buffer_get_at(self, self->index + 1));
}

t_token *token_buffer_peek_prev(t_token_buffer *self)
{
	if (token_buffer_is_empty(self))
		return (NULL);
	return (token_buffer_get_at(self, self->index - 1));
}

uint64_t token_buffer_get_curr_index(t_token_buffer *self)
{
	return (self->index);
}

bool token_buffer_end_of_buffer(t_token_buffer *self, uint64_t n)
{
	return (n > self->count);
}

void token_buffer_deinit(t_allocator *allocator, t_token_buffer *self)
{
	t_token *token;

	assert(allocator != NULL);
	assert(self != NULL);
	while (!token_buffer_is_empty(self))
	{
		token = token_buffer_pop(self);
		token_destroy(allocator, token);
	}
	self->index = 0;
}

t_token_buffer *token_buffer_destroy(t_allocator *allocator, t_token_buffer *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	token_buffer_deinit(allocator, self);
	vector_destroy(self->tokens);
	allocator->destroy(allocator, self);
	return (NULL);
}
