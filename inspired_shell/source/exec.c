#include "../minishell.h"

void	execute_command(t_minishell *self)
{
	int	pid;
	char	**cmd_vector;

	if (!self->cmd_table->head)
		return ;
	pid = fork();
	cmd_vector = self->cmd_table->head->cmd_vector;
	if (pid < 0)
	{
		perror("execute_command");
		minishell_destroy(self);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(cmd_vector[0], cmd_vector, self->envp);
		minishell_destroy(self);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
}
