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

// void hashmap_test(t_hashmap *map, char **envp)
// {
// 	uint64_t idx;
// 	uint64_t i;
// 	char    *k;
// 	char    *v;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		idx = string_index_of(envp[i], '=');
// 		k = string_nclone(envp[i], idx);
// 		v = string_clone(&envp[i][idx + 1]);
// 		hashmap_put(map, k, v);
// 		memory_dealloc(k);
// 		memory_dealloc(v);
// 		i += 1;
// 	}
// 	char *temp = hashmap_get(map, "PATH");
// 	printf("PATH=%s\n", temp);
// }

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	init_exceptions(argv[0]);
	shell = shell_create(argc, argv, envp);
	while (shell_run(shell))
		shell_clear(shell);
	shell = shell_destroy(shell);
	return (0);
}
