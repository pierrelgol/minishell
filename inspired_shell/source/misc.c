/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:42:25 by bifernan          #+#    #+#             */
/*   Updated: 2024/05/13 11:42:28 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_path_variable(char *envp[])
{
	int	i;

	if (!envp[0])
		return (NULL);
	i = 0;
	while (ft_memcmp("PATH", envp[i], 4))
		i++;
	if (!envp[i])
		return (NULL);
	return (&envp[i][5]);
}

void	display_prompt(void)
{
	ft_printf("%s%s%s", COLOR_GREEN, "minishell $> ", COLOR_RESET);
}

void	display_parsing_info(t_minishell *sh)
{
	if (!sh->token_list->size)
		return ;

	if (sh->token_list->size)
	{
		ft_printf("\n######  TOKEN LIST  #######\n");
		token_list_print_value(sh->token_list);
		token_list_print_type(sh->token_list);
		/////////////////////////////////////////////		
		ft_printf("\n######    PARSER    #######\n");
		ft_printf("Processed tokenList : \n");
		token_list_print_type(sh->token_list);
		//////////////////////////////////////////////
	}
	if (sh->cmd_table->size)
	{
		ft_printf("\n##### COMMAND TABLE #######\n");
		ft_printf("cmd_table size = %d\n", sh->cmd_table->size);
		ft_printf("cmd_vector :\n");
		print_array(sh->cmd_table->head->cmd_vector);
	}
}

void	remove_new_line(t_minishell *self)
{
	int	i;

	i = 0;
	if (!self->line)
		return ;
	while (self->line[i] != '\0')
	{
		if (self->line[i] == '\n')
			self->line[i] = '\0';
		i++;
	}
}
