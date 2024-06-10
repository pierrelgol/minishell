#include "../../header/minishell.h"


void	tokeniser(t_minishell *self)
{
	char	*token;

	if (!self->line)
		return ;
	minishell_get_extended_line(self);
	if (!self->extended_line)
		return ;
	while ((token = ft_strtok(self->extended_line, '@')) != NULL)
		token_list_add_back(self->token_list, token);
}
