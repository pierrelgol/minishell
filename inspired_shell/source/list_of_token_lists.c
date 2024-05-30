#include "../minishell.h"

int	count_pipe(tokenList *self)
{
	t_token	*temp;
	int	count;

	if (!self || !self->head)
		return (-1);
	temp = self->head;
	count = 0;
	while (temp != NULL)
	{
		if (temp->type == PIPE)
			count++;
		temp = temp->next;
	}
	return (count);
}

int	tokenArray_tokenList_count(tokenList *self) //we have pipe_count + 1 tokenLists to make
{
	return (count_pipe(self) + 1); //if this is equal to 0 that's a problem
}

tokenList	**tokenArray_init(t_minishell *sh)
{
	int	size;
	int	i;
	tokenList	**token_array;

	if (!sh || !sh->token_list)
	{
		minishell_destroy(sh);
		exit(EXIT_FAILURE);
	}
	size = tokenArray_tokenList_count(sh->token_list);
	if (!size)
	{
		minishell_destroy(sh);
		exit(EXIT_FAILURE);
	}
	token_array = (tokenList **)malloc(sizeof(tokenList *) * (size + 1));
	if (!token_array)
	{
		minishell_destroy(sh);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < size) //we initialize an array of tokenLists
	{
		token_array[i] = token_list_new();
		if (!token_array)
		{
			minishell_destroy(sh);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	token_array[i] = NULL;
	return (token_array);
}

//tokenArray_add_tokenList()

void	tokenArray_destroy(tokenList **token_array)
{
	int	i;

	if (!token_array)
		return ;
	i = 0;
	while (token_array[i])
	{
		token_list_destroy(token_array[i]); //tokenLists destruction
		i++;
	}
	free(token_array[i]);
	free(token_array);
}

int	tokenArray_size(tokenList **array)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (array[i])
	{
		i++;
		size++;
	}
	return (size);
}

void	set_tokenArray(t_minishell *sh)
{
	if (!sh || !sh->token_list || !sh->token_list->head)
		return ;
	sh->token_array = tokenArray_init(sh);
	//ft_printf("A tokenArray of size %d has been initialized\n", tokenArray_size(sh->token_array));
	//tokenArray_destroy(sh->token_array);
	fill_tokenArray(sh);
	//print_tokenArray(sh->token_array);
	//ft_printf("tokenArray TERMINATED\n");
}

void	tokenCopy_add_back(tokenList *tklist, t_token *token)
{
	t_token	*new_node;

	if (!tklist || !token)
		return ;
	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
	{
		token_list_destroy(tklist);
		return ;
	}
	new_node->id = tklist->size;
	new_node->value = token->value;
	new_node->size = token->size;
	new_node->type = token->type;
	new_node->next = NULL;
	new_node->prev = NULL;
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

void	fill_tokenArray(t_minishell *sh)
{
	t_token	*temp;
	int	i;

	if (!sh || !sh->token_array || !sh->token_list)
		return ;
	temp = sh->token_list->head;
	i = 0;
	while (temp != NULL)
	{
		if (temp->type != PIPE)
			tokenCopy_add_back(sh->token_array[i], temp);
		else
			i++;
		temp = temp->next;
	}
}

void	print_tokenArray(tokenList **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		token_list_print_value(array[i]);
		token_list_print_type(array[i]);
		i++;
	}
}






