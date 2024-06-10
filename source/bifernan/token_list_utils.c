#include "../../header/minishell.h"

tokenList	*token_list_new(void)
{
	tokenList	*tokenlist;
	
	tokenlist = (tokenList *)malloc(sizeof(tokenList));
	if (!tokenlist)
		return (NULL);
	tokenlist->size = 0;
	tokenlist->head = NULL;
	tokenlist->tail = NULL;
	return (tokenlist);
}

void	token_list_add_back(tokenList *tklist, t_token *token)
{
	t_token_2	*new_node;

	if (!tklist || !token)
		return ;
	new_node = (t_token_2 *)malloc(sizeof(t_token_2));
	if (!new_node)
	{
		token_list_clear(tklist);
		return ;
	}
	new_node->id = tklist->size;
	new_node->value = token->ptr;
	new_node->size = token->len;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->left_quote = NULL;
	new_node->right_quote = NULL;
	set_token_type(new_node);
	if (!tklist->size)
	{
		tklist->head = new_node;
		tklist->tail = new_node;
	}
	else
	{
		new_node->prev = tklist->tail;
		tklist->tail->next = new_node;
		tklist->tail = new_node;
	}
	tklist->size += 1;
}

void	token_list_clear(tokenList *self)
{
	t_token_2	*temp;
	t_token_2	*to_delete;

	if (!self)
		return ;
	temp = self->head;
	while (temp != NULL)
	{
		to_delete = temp;
		temp = to_delete->next;
		free(to_delete);
		self->size -= 1;
	}
	self->head = NULL;
	self->tail = NULL;
}

void	token_list_destroy(tokenList *self)
{
	t_token_2	*temp;
	t_token_2	*to_delete;

	if (!self)
		return ;
	temp = self->head;
	while (temp != NULL)
	{
		to_delete = temp;
		temp = to_delete->next;
		free(to_delete);
	}
	free (self);
}

void	token_list_print_value(tokenList *self)
{
	t_token_2	*temp;

	if (!self)
		return ;
	temp = self->head;
	ft_printf("\n");
	while (temp != NULL)
	{
		ft_printf("[%s]->", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	token_list_print_type(tokenList *self)
{
	t_token_2	*temp;
	char	*type;

	if (!self)
		return ;
	temp = self->head;
	ft_printf("\n");
	while (temp != NULL)
	{
		if (temp->type == 0)
			type = "UNKNOWN";
		if (temp->type == 1)
			type = "IDENTIFIER";
		if (temp->type == 2)
			type = "MINUS";
		if (temp->type == 3)
			type = "PIPE";
		if (temp->type == 4)
			type = "DOT";
		if (temp->type == 5)
			type = "LEFT_PARENTHESIS";
		if (temp->type == 6)
			type = "RIGHT_PARENTHESIS";
		if (temp->type == 7)
			type = "INPUT_REDIRECT";
		if (temp->type == 8)
			type = "OUTPUT_REDIRECT";
		if (temp->type == 9)
			type = "APPEND_REDIRECT";
		if (temp->type == 10)
			type = "AMPERSAND";
		if (temp->type == 11)
			type = "SEMICOLON";
		if (temp->type == 12)
			type = "EXCLAMATION";
		if (temp->type == 13)
			type = "KEYWORD";
		if (temp->type == 14)
			type = "PATH";
		if (temp->type == 15)
			type = "FILE";
		if (temp->type == 16)
			type = "EXISTING FILE";
		if (temp->type == 17)
			type = "UNEXISTING FILE";
		if (temp->type == 18)
			type = "CMD_OPTION";
		if (temp->type == 19)
			type = "DOUBLE_QUOTE";
		if (temp->type == 20)
			type = "SINGLE_QUOTE";
		if (temp->type == 21)
			type = "CMD";
		if (temp->type == 22)
			type = "CMD_ARG";
		if (temp->type == 23)
			type = "HERE_DOC";
		if (temp->type == 24)
			type = "HD_DELIM";
		if (temp->type == 25)
			type = "SPC";
		if (temp->type == 26)
			type = "DOLLAR";
		ft_printf("[%s]->", type);
		temp = temp->next;
	}
	ft_printf("\n");
}
