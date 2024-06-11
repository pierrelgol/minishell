#include "../../header/minishell.h"


void	expect(t_minishell *minishell, void *ptr, char *message)
{
	if (!ptr)
	{
		abort();
		minishell_destroy(minishell);
		perror(message);
		exit(EXIT_FAILURE);
	}
}
