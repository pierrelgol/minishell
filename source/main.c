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

int main(int argc, char **argv, char **envp)
{
	t_shell *shell;

	init_exceptions(argv[0]);
	shell = shell_create(argc, argv, envp);
	if (!shell)
		abort();
	shell = shell_destroy(shell);
	return (0);
}
