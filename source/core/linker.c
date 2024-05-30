/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell_linker *shell_linker_create(t_allocator *allocator, t_shell_env *env, t_shell_lexer *lexer)
{
	t_shell_linker *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->lexer = lexer;
	self->env = env;
	self->payload_vector = vector_create(allocator);
	self->paths = NULL;
	self->it = it_create(allocator);
	return (self);
}

void shell_linker_init(t_allocator *allocator, t_shell_linker *self)
{
	char *path;
	assert(allocator != NULL);
	assert(self != NULL);
	path = shell_env_get(self->env, "PATH");
	self->paths = string_split_scalar(allocator, path, ':');
	it_init_with_split(self->it, self->paths);
}

void shell_linker_deinit(t_allocator *allocator, t_shell_linker *self)
{
	uint64_t i;

	assert(allocator != NULL);
	assert(self != NULL);
	i = 0;
	if (self->paths)
	{
		while (self->paths[i])
			allocator->destroy(allocator, self->paths[i++]);
		allocator->destroy(allocator, self->paths);
	}
	self->paths = NULL;
	it_reset(self->it);
}

void shell_linker_print(t_shell_linker *self)
{
	char *path;

	print(1, "--------------------------------\n");
	print(1, "shell_linker output\n");
	it_save(self->it);
	while (!it_end(self->it))
	{
		path = (char *) it_peekcurr(self->it);
		if (path)
			print(1, "%s\n", path);
		it_next(self->it);
	}
	it_restore(self->it);
	print(1, "--------------------------------\n");
}

t_shell_linker *shell_linker_destroy(t_allocator *allocator, t_shell_linker *self)
{
	assert(self != NULL);
	assert(allocator != NULL);

	it_destroy(self->it);
	vector_destroy(self->payload_vector);
	allocator->destroy(allocator, self);
	return (NULL);
}
