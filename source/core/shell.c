/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:29:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 13:29:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell *shell_create(int32_t argc, char **argv, char **envp)
{
	t_shell *self;

	self = (t_shell *) memory_alloc(sizeof(t_shell));
	if (!self)
		return (NULL);
	self->argc = argc;
	self->argv = argv;
	self->envp = envp;
	return (self);
}

t_shell *shell_destroy(t_shell *self)
{
	if (self)
	{
		memory_dealloc(self);
	}
	return (NULL);
}
