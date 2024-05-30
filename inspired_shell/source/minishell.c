/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:19:15 by bifernan          #+#    #+#             */
/*   Updated: 2024/05/13 11:51:28 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	minishell_get_extended_line(t_minishell *self)
{
	if (!self || !self->line)
		return ;
	self->extended_line = string_add_delimiter(self->line, self->sep, '@');
	if (!self->extended_line)
	{
		minishell_destroy(self);
		exit(EXIT_FAILURE);
	}
}

t_minishell *allocate_minishell(void)
{
	t_minishell	*minishell;

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	if (!minishell)
	{
		perror("allocate_minishell");
		exit(EXIT_FAILURE);
	}
	return (minishell);
}

void	set_path_variable(t_minishell *minishell, char *envp[])
{
	if (!envp[0])
		minishell->path_variable = NULL;
	else
	{
		minishell->path_variable = get_path_variable(envp);
		expect(minishell, minishell->path_variable, "minishell_create");
	}
}

t_minishell	*minishell_create(char *envp[])
{
	t_minishell	*self;

	self = allocate_minishell();
	set_path_variable(self, envp);
	self->envp = envp;
	self->line = NULL;
	self->extended_line = NULL;
	self->sep = "!#$%^&*()_-+={[}]\\|'\";:/?.>,<";
	self->token_list = token_list_new();
	self->token_array = NULL;
	if (!self->token_list)
	{
		minishell_destroy(self);
		perror("minishell_create");
		exit(EXIT_FAILURE);
	}
	self->cmd_table = cmdTable_create() ;
	if (!self->cmd_table)
	{
		minishell_destroy(self);
		perror("minishell_create");
		exit(EXIT_FAILURE);
	}
	return (self);
}

void	minishell_destroy(t_minishell *self)
{
	if (!self)
		return ;
	if (self->line)
		free(self->line);
	if (self->extended_line)
		free(self->extended_line);
	if (self->token_list)
		token_list_clear(self->token_list);
	if (self->cmd_table)
		cmdTable_destroy(self->cmd_table);
	free(self);
}

void	minishell_clear(t_minishell *self)
{
	if (!self)
		return ;
	free(self->line);
	self->line = NULL;
	free(self->extended_line);
	self->extended_line = NULL;
	token_list_clear(self->token_list);
	cmdTable_clear(self->cmd_table);
	tokenArray_destroy(self->token_array);
	self->token_array = NULL;
}

void	minishell_loop(t_minishell *self)
{
	if (!self)
		return ;
	while (1)
	{
		display_prompt();
		self->line = get_next_line(STDIN_FILENO);
		remove_new_line(self);
		if (!self->line)
			break;
		tokeniser(self);
		guesser(self);
		//display_parsing_info(self);
		//execute_command(self);
		set_tokenArray(self);
		fill_cmd_table(self);
		//print_cmd_table(self);
		parent_process(self);
		minishell_clear(self);
	}
}
