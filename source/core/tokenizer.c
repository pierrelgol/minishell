/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_tokenizer *shell_tokenizer_create(t_allocator *allocator)
{
	t_shell_tokenizer *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	return (self);
}

void shell_tokenizer_init(t_allocator *allocator, t_shell_tokenizer *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
}

void shell_tokenizer_deinit(t_allocator *allocator, t_shell_tokenizer *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
}

t_shell_tokenizer *shell_tokenizer_destroy(t_allocator *allocator, t_shell_tokenizer *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	allocator->destroy(allocator, self);
	return (NULL);
}
