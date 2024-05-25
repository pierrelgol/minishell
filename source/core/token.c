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
	assert(self != NULL);
	return (self);
}

void token_init(t_allocator *allocator, t_token *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
}
void token_deinit(t_allocator *allocator, t_token *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
}

t_token *token_destroy(t_allocator *allocator, t_token *self)
{
	assert(self != NULL);
	assert(allocator != NULL);
	allocator->destroy(allocator, self);
	return (NULL);
}
