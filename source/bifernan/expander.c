#include "../../header/minishell.h"


int	has_dollar_token(tokenList *self)
{
	t_token_2	*temp;

	if (!self)
		return (0);
	temp = self->head;
	while (temp != NULL)
	{
		if (temp->type == DOLLAR)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	expander(t_minishell *self)
{
	t_token_2	*temp;

	if (!self)
		return ;
	if (!has_dollar_token(self->token_list))
		return ;
	temp = self->token_list->head;
	while (temp != NULL)
	{
		if (temp->type == DOLLAR)
			replace_key_by_value(self, temp->next);
		temp = temp->next;
	}
	remove_all_dollar_tokens(self->token_list);
}

char	*find_value(t_minishell *sh, t_token_2 *key)
{
	char	**env;
	int	i;

	if (!sh || !key)
		return (NULL);
	i = 0;
	env = sh->envp;
	while (env[i] != NULL)
	{
		if (ft_memcmp(key->value, env[i], key->size) == 0)
			return (&env[i][key->size + 1]);
		i++;
	}
	return (NULL);
}

void	replace_key_by_value(t_minishell *sh, t_token_2 *key)
{
	char	*value;

	if (!sh || !key || token_is_hard_quoted(key))
		return ;
	value = find_value(sh, key);
	key->value = value;
}

int	is_dollar_token(t_token_2 *self)
{
	return (self->type == DOLLAR);
}

void	remove_all_dollar_tokens(tokenList *self) //remove all == mauvaise idee ?
{
	t_token_2	*temp;

	if (!self)
		return ;
	temp = self->head;
	while (temp != NULL)
	{
		if (is_dollar_token(temp) && !token_is_hard_quoted(temp))
		{
			temp = temp->next;
			remove_token(self, temp->prev);
		}
		else
			temp = temp->next;
	}
}
