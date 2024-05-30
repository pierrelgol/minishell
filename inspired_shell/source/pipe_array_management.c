#include "../minishell.h"

void	create_pipe_array(t_minishell *sh, cmdTable *self)
{
	int	i;

	if (!sh || !self)
		return ;
	self->pipe_number = self->size - 1;
	if (!self->pipe_number)
		return ;
	//main array containing all the 2 sized array for pipe
	self->pipe_array = (int **)malloc(sizeof(int *) * self->pipe_number);
	if (!self->pipe_array)
	{
		perror("create_pipe_array : allocation failed\n");
		minishell_destroy(sh);
		exit(EXIT_FAILURE);
	}
	i = 0;
	//small 2 sized array to be processed by the pipe cmd
	while (i < self->pipe_number)
	{
		self->pipe_array[i] = (int *)malloc(sizeof(int) * 2);
		if (!self->pipe_array[i])
		{
			while (i > 0)
			{
				free(self->pipe_array[i]);
				i--;
			}
			free(self->pipe_array);
			perror("create_pipe_array : allocation failed\n");
			minishell_destroy(sh);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	destroy_pipe_array(cmdTable *self)
{
	int	**pipe_array;
	int	i;

	pipe_array = self->pipe_array;
	if (!pipe_array)
		return ;
	i = 0;
	while (i < self->pipe_number)
	{
		free(pipe_array[i]);
		i++;
	}
	free(pipe_array);
	self->pipe_array = NULL;
}
