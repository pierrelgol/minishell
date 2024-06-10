#include "../../header/minishell.h"


t_token_2	*get_first_quote(tokenList *self)
{
	t_token_2	*temp;
	
	if (!self)
		return (NULL);
	temp = self->head;
	while (self != NULL)
	{
		if (temp->type == SINGLE_QUOTE || temp->type == DOUBLE_QUOTE)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_token_2 *get_next_quote(t_token_2 *self)
{
	t_token_2	*temp;

	if (!self)
		return (NULL);
	temp = self->next;
	while (temp != NULL)
	{
		if (temp->type == SINGLE_QUOTE || temp->type == DOUBLE_QUOTE)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_token_2 *get_enclosing_quote(t_token_2 *self) // A partir d'une quote ouvrante
{
	t_token_2	*temp;

	if (!self)
		return (NULL);
	temp = self->next;
	while (temp != NULL)
	{
		if (temp->type == self->type)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	set_left_and_right_quote(t_token_2 *self, t_token_2 *opening_quote, t_token_2 *enclosing_quote)
{
	t_token_2	*temp;

	if (!self || !opening_quote || !enclosing_quote)
		return ;
	self->left_quote = opening_quote;
	self->right_quote = enclosing_quote;
	temp = self->next;
	while (temp != enclosing_quote && temp != NULL)
	{
		temp->left_quote = opening_quote;
		temp->right_quote = enclosing_quote;
		temp = temp->next;
	}
}

int	token_is_hard_quoted(t_token_2 *self)
{
	if (!self->left_quote)
		return (0);
	return (self->left_quote->type == SINGLE_QUOTE);
}
