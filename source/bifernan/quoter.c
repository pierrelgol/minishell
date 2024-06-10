#include "../../header/minishell.h"


int	tokenList_has_quotes(tokenList *tklist)
{
	t_token_2	*temp;

	if (!tklist)
		return (-1);
	temp = tklist->head;
	while (temp != NULL)
	{
		if (temp->type == SINGLE_QUOTE || temp->type == DOUBLE_QUOTE)
			return (1);
		temp = temp->next;

	}
	return (0);
}

void	remove_token(tokenList *tklist, t_token_2 *self)
{
	if (!tklist || !self)
		return ;
	if (self->prev == NULL)
		tklist->head = self->next;
	else
		self->prev->next = self->next;
	if (self->next == NULL)
		tklist->tail = self->prev;
	else
		self->next->prev = self->prev;
	free(self);
	tklist->size -= 1;
}

void	remove_all_space_tokens(tokenList *tklist)
{
	t_token_2	*temp;

	if (!tklist ||tokenList_has_quotes(tklist))
		return ;
	temp = tklist->head;
	while (temp != NULL)
	{
		if (temp->type == SPC)
		{
			temp = temp->next;
			remove_token(tklist, temp->prev);
		}
		else
			temp = temp->next;
	}
}

void	quoter(t_minishell *self)
{
	if (!self || !self->token_list)
		return ;
	if (!tokenList_has_quotes(self->token_list))
	{
		expander(self);	
		remove_all_space_tokens(self->token_list);
		refresh_token_id(self->token_list);
		display_token_id(self->token_list);
		return ;
	}
	link_token_to_quotes(self->token_list);
	expander(self);	
	display_token_quotes(self->token_list);
	remove_all_unclosed_space_tokens(self->token_list);
	refresh_token_id(self->token_list);
}

void	link_token_to_quotes(tokenList *self)
{
	t_token_2	*temp;
	t_token_2	*first_quote;
	t_token_2 *last_quote;
	
	first_quote = get_first_quote(self);
	last_quote = get_enclosing_quote(first_quote);
	while (first_quote != NULL)
	{
		temp = first_quote->next;
		set_left_and_right_quote(temp, first_quote, last_quote);
		first_quote = get_next_quote(last_quote);
		last_quote = get_enclosing_quote(first_quote);
	}
}

void	find_left_quote(t_token_2 *self)
{
	t_token_2	*temp;

	if (!self)
		return ;
	temp = self->prev;
	while (temp != NULL)
	{
		if (temp->left_quote) //test
		{
			self->left_quote = temp->left_quote;	
			return ;
		}
		else
		{
			if (temp->type == SINGLE_QUOTE || temp->type == DOUBLE_QUOTE)
			{
				self->left_quote = temp;
				return ;
			}
			temp = temp->prev;
		}
	}
}
		
void	find_right_quote(t_token_2 *self)
{
	t_token_2	*temp;

	if (!self)
		return ;
	temp = self->next;
	while (temp != NULL)
	{
		if (self->left_quote)
		{
			if (temp->type == self->left_quote->type)
			{
				self->right_quote = temp;
				return ;
			}
		}
		//else
		//{
		//	if ((temp->type == SINGLE_QUOTE || temp->type == DOUBLE_QUOTE)) //&& temp->type == self->left_quote->type)
		//	{
		//		self->right_quote = temp;
		//		return ;
		//	}
		//}
		temp = temp->next;
	}
}

void	refresh_token_id(tokenList *self)
{
	t_token_2	*temp;
	int	id;

	if (!self)
		return ;
	id = 0;
	temp = self->head;
	while (temp != NULL)
	{
		temp->id = id;
		id++;
		temp = temp->next;
	}
}

void	display_token_quotes(tokenList *self)
{
	t_token_2	*temp;

	if (!self)
		return ;
	temp = self->head;
	while (temp != NULL)
	{
		//if (temp->type == SINGLE_QUOTE || temp->type == DOUBLE_QUOTE)
		//	ft_printf("[quote]->");
		if (!temp->left_quote && !temp->right_quote)
			ft_printf("[N:%d:N]->", temp->id);
		else if (temp->left_quote && temp->right_quote)
			ft_printf("[%d:%d:%d]->", temp->left_quote->id, temp->id, temp->right_quote->id);
		else if (temp->left_quote && !temp->right_quote)
			ft_printf("[%d:%d:N]->", temp->left_quote->id, temp->id);
		else if (!temp->left_quote && temp->right_quote)
			ft_printf("[N:%d:%d]->", temp->id, temp->right_quote->id);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	display_token_id(tokenList *self)
{
	t_token_2	*temp;

	if (!self)
		return ;
	temp = self->head;
	while (temp != NULL)
	{
		ft_printf("[%d]->", temp->id);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	is_enclosed_token(t_token_2 *self)
{
	return (self->left_quote && self->right_quote);
}

int	is_space_token(t_token_2 *self)
{
	return (self->type == SPC);
}

int	is_unclosed_space_token(t_token_2 *self)
{
	return (!is_enclosed_token(self) && is_space_token(self));
}

void	remove_all_unclosed_space_tokens(tokenList *self)
{
	t_token_2	*temp;

	if (!self)
		return ;
	temp = self->head;
	while (temp != NULL)
	{
		if (is_unclosed_space_token(temp))
		{
			temp = temp->next;
			remove_token(self, temp->prev);
		}
		else
			temp = temp->next;
	}
}
