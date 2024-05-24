/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:00:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/22 04:00:47 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/c-stacktrace.h"
#include "../header/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_allocator *allocator;
	t_shell     *shell;

	init_exceptions(argv[0]);
	allocator = gpa_init();
	shell = shell_create(allocator, argc, argv, envp);
	shell_run(shell);
	shell = shell_destroy(shell);
	return (0);
}
