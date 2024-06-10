#include "../../header/minishell.h"


void	fill_cmd_table(t_minishell *sh)
{
	t_token_2	*temp;
	int	i;

	if (!sh || !sh->token_array)
		return ;
	i = 0;
	while (sh->token_array[i])
	{
		
		temp = sh->token_array[i]->head;
		while (temp != NULL)
		{
			if (temp->type == CMD)
				cmdTable_add_back(sh->cmd_table, sh, temp, sh->token_array[i]);
			temp = temp->next;
		}
		i++;
	}
}

void	print_cmd_table(t_minishell *sh)
{
	t_cmd	*temp;

	if (!sh || !sh->cmd_table)
		return ;
	temp = sh->cmd_table->head;
	while (temp != NULL)
	{
		ft_printf("COMMAND VECTOR :\n");
		print_array(temp->cmd_vector);
		ft_printf("INPUT VECTOR :\n");
		print_array(temp->input_vector);
		ft_printf("OUTPUT VECTOR :\n");
		print_array(temp->output_vector);
		ft_printf("APPEND VECTOR :\n");
		print_array(temp->o_append_vector);
		temp = temp->next;
	}
}
