#include "../minishell.h"

int	main(int argc, char *argv[], char *envp[])
{	
	t_minishell	*minishell;

	if (argc != 1)
		return (1);
	(void)argv;
	minishell = minishell_create(envp);
	minishell_loop(minishell);			
	
	minishell_destroy(minishell);
	return (0);
}
