#include "../minishell.h"
#include <sys/wait.h>

int	pipe_has_been_used(int pipe_uses)
{
	return (pipe_uses == 2);
}

void	open_pipe(cmdTable *self)
{
	if (!self)
		return ;
	pipe(self->pipe_array[self->pipe_index]);
}

void	actualize_pipe_index(cmdTable *self)
{
	self->pipe_index += 1;
}

void	parent_process(t_minishell *sh)
{
	cmdTable	*cmd_table;
	t_cmd	*executing_cmd;
	int	pid;

	if (!sh || !sh->cmd_table || ! sh->cmd_table->head)
		return ;
	cmd_table = sh->cmd_table;
	executing_cmd = cmd_table->head;
	create_pipe_array(sh, cmd_table);
	while (executing_cmd)
	{
		if (!is_last_command(executing_cmd))
		{
			open_pipe(cmd_table);
			actualize_pipe_index(cmd_table);
		}
		pid = fork();
		if (pid == 0)
			child_process(sh, cmd_table, executing_cmd);
		if (!is_first_command(executing_cmd))
		{
			close(cmd_table->pipe_array[executing_cmd->id - 1][0]);
			close(cmd_table->pipe_array[executing_cmd->id - 1][1]);
		}
		wait(NULL);
		executing_cmd = executing_cmd->next;
	}
}

int	is_first_command(t_cmd *self)
{
	return (self->prev == NULL);
}

int	is_last_command(t_cmd *self)
{
	return (self->next == NULL);
}

int	is_the_only_cmd(t_cmd *self)
{
	return (is_first_command(self) && is_last_command(self));
}

int	is_in_middle_cmd(t_cmd *self)
{
	return (!is_first_command(self) && !is_last_command(self));
}

void	child_process(t_minishell *sh, cmdTable *cmd_table, t_cmd *self)
{
	if (!sh || !cmd_table || !self)
		return ;
	if (is_the_only_cmd(self))
		execute(sh, self);
	if (is_first_command(self))
	{
		close(cmd_table->pipe_array[0][0]);
		dup2(cmd_table->pipe_array[0][1], STDOUT_FILENO);
		close(cmd_table->pipe_array[0][1]);
		execute(sh, self);
	}
	if (is_in_middle_cmd(self))
	{
		//si c'est la deuxieme commande, pipe index vaut 2	
		close(cmd_table->pipe_array[cmd_table->pipe_index - 2][1]);
		close(cmd_table->pipe_array[cmd_table->pipe_index - 1][0]);
		dup2(cmd_table->pipe_array[cmd_table->pipe_index - 2][0], STDIN_FILENO);
		dup2(cmd_table->pipe_array[cmd_table->pipe_index - 1][1], STDOUT_FILENO);
		close(cmd_table->pipe_array[cmd_table->pipe_index - 2][0]);
		close(cmd_table->pipe_array[cmd_table->pipe_index - 1][1]);
		execute(sh, self);
	}
	if (is_last_command(self))
	{
		close(cmd_table->pipe_array[cmd_table->pipe_index - 1][1]);
		dup2(cmd_table->pipe_array[cmd_table->pipe_index - 1][0], STDIN_FILENO);
		close(cmd_table->pipe_array[cmd_table->pipe_index - 1][0]);
		execute(sh, self);
	}
}

int	cmd_has_input_redirect(t_cmd *self)
{
	if (!self)
		return (-1);
	return (self->input_vector[0] != NULL);
}

int	cmd_has_output_redirect(t_cmd *self)
{
	if (!self)
		return (-1);
	return (self->output_vector[0] != NULL);
}

void	execute(t_minishell *sh, t_cmd *self)
{
	if(!sh || !self)
		return ;
	self->fd_array[0] = open_all_input_files_and_get_last(self->input_vector);
	self->fd_array[1] = open_all_output_files_and_get_last(self->output_vector);
	if (cmd_has_input_redirect(self))
	{
		dup2(self->fd_array[0], STDIN_FILENO);
		close(self->fd_array[0]);
	}
	if (cmd_has_output_redirect(self))
	{
		dup2(self->fd_array[1], STDOUT_FILENO);
		close(self->fd_array[1]);
	}
	execve(self->cmd_vector[0], self->cmd_vector, sh->envp);	
	minishell_destroy(sh);
}
