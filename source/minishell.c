/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:22:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"
#include "../header/c-stacktrace.h"

int64_t g_signal = SH_SIG_WORK;

int main(int argc, char **argv, char **envp)
{
	t_allocator *allocator;
	t_shell     *shell;

	init_exceptions(argv[0]);
	allocator = gpa_init();
	shell = shell_create(allocator, argc, argv, envp);
	if (argc == 1)
	{
		while (signal_get() != SH_SIG_DONE)
		{
			shell_init(allocator, shell);
			shell_main(allocator, shell);
			shell_deinit(allocator, shell);
		}
	}
	return (0);
}
