/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:31:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_builtin_env *builtin_env_create(t_allocator *allocator)
{
	t_builtin_env *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	return (self);
}

t_builtin_env *builtin_env_destroy(t_allocator *allocator, t_builtin_env *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	allocator->destroy(allocator, self);
	return (NULL);
}
