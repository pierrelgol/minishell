/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:25:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 13:25:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/c-stacktrace.h"
#include "../header/minishell.h"


int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	init_exceptions(argv[0]);
	// @STEP01 creating the shell --> ./source/core/shell.c
	shell = shell_create(argc, argv, envp);
	// @STEP08 we now have a working shell and can run it --> ./source/core/shell.c
	while (shell_run(shell))
	{
		//@STEP24 we now call every clear method from the structures created in @STEP01
		shell_clear(shell);
		// @STEP25 we go back to @STEP08 over and over until
		// input == NULL
	}
	// @STEP26 we destroy and clean everything
	shell = shell_destroy(shell);
	return (0);
}
