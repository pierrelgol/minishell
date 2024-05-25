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

int64_t g_signal;

int main(int argc, char **argv, char **envp)
{
	t_allocator *allocator;
	t_shell     *shell;

	init_exceptions(argv[0]);
	allocator = gpa_init();
	shell = shell_create(allocator, argc, argv, envp);
	if (argc == 1)
	{
		while (g_signal != SIG_STOP)
		{
			shell_init(allocator, shell);
			// shell_main(allocator, shell);
			shell_deinit(allocator, shell);
			g_signal = SIG_STOP;
		}
	}
	shell = shell_destroy(allocator, shell);
	allocator = gpa_deinit(allocator);
	return (0);
}
