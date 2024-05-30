#include "../minishell.h"


void	cmd_table_monitoring(cmdTable *self)
{
	static int	call;

	ft_printf("###  cmdTable [%d] ###\n", call);
	call++;
	ft_printf("size        : %d\n", self->size);
	ft_printf("pipe_number : %d\n", self->pipe_number);
	ft_printf("pipe_index  : %d\n", self->pipe_index);
	if (self->pipe_array)
		ft_printf("pipe_array  : enabled\n");
	else
		ft_printf("pipe_array  : disabled\n");
	ft_printf("### monitoring end ###\n");
	ft_printf("\n");
}
