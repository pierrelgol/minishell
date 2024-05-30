#include "../minishell.h"

int	vector_size(tokenList *tklist, t_token_type type)
{
	t_token	*temp;
	int	count;

	if (!tklist || !tklist->head)
		return (-1);
	count = 0;
	temp = tklist->head;
	while (temp != NULL)
	{
		if (temp->type == type)
			count++;
		temp = temp->next;
	}
	return (count);
}

void	fill_io_vector(tokenList *tklist, char **io_vector, t_token_type type)
{
	t_token	*temp;
	int	i;
	
	if (!tklist || !io_vector)
		return ;
	temp = tklist->head;
	i = 0;
	while (temp != NULL)
	{
		if (temp->next)
		{
			if (temp->type == type)
			{
				io_vector[i] = temp->next->value;
				i++;
			}
		}
		else
		{
			if (temp->type == type)
				ft_printf("parse error near ... \n");
		}
		temp = temp->next;
	}
	io_vector[i] = NULL;
}

char	**io_vector_init(tokenList *tklist, t_token_type type)
{
	char	**io_vector;
	int	size;

	if (!tklist || !tklist->head)
		return (NULL);
	size = vector_size(tklist, type);
	io_vector = (char **)malloc(sizeof(char *) * (size + 1));
	if (!io_vector)
		return (NULL);
	fill_io_vector(tklist, io_vector, type);
	return (io_vector);
}

void	io_vector_destroy(char **io_vector)
{
	int	i;

	i = 0;
	while (io_vector[i])
	{
		i++;
	}
	free(io_vector[i]);
	free(io_vector);
}
