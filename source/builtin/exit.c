/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:31:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_builtin_exit *builtin_exit_create(t_allocator *allocator)
{
	t_builtin_exit *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	return (self);
}

t_builtin_exit *builtin_exit_destroy(t_allocator *allocator, t_builtin_exit *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	allocator->destroy(allocator, self);
	return (NULL);
}
