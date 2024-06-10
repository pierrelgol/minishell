#include "../../header/minishell.h"


cmdTable	*cmdTable_create(void)
{
	cmdTable	*self;

	self = (cmdTable *)malloc(sizeof(cmdTable));
	if (!self)
		return (NULL);
	self->size = 0;
	self->pipe_number = 0;
	self->pipe_index = 0;
	self->pipe_array = NULL;
	self->head = NULL;
	self->tail = NULL;
	return (self);
}

void	cmdTable_destroy(cmdTable *self)
{
	t_cmd	*temp;
	t_cmd	*to_delete;
	if (!self)
		return ;
	destroy_pipe_array(self);
	temp = self->head;
	while (temp != NULL)
	{
		to_delete = temp;
		free(to_delete->cmd_vector);
		free(to_delete);
		temp = temp->next;
	}
	free(self);
}

void	cmdTable_clear(cmdTable *self)
{
	t_cmd	*temp;
	t_cmd	*to_delete;
	if (!self)
		return ;
	destroy_pipe_array(self);
	temp = self->head;
	self->pipe_index = 0;
	while (temp != NULL)
	{
		to_delete = temp->next;
		free_array(&temp->cmd_vector);
		io_vector_destroy(temp->input_vector);
		io_vector_destroy(temp->output_vector);
		io_vector_destroy(temp->o_append_vector);
		free(temp);
		self->size -= 1;
		temp = to_delete;
	}
	self->head = NULL;
	self->tail = NULL;
}

int	get_cmd_vector_size(t_token_2 *cmd_token)
{
	t_token_2	*temp;
	int	size;
	if (!cmd_token)
		return (-1);
	temp = cmd_token;
	size = 1;
	temp = temp->next;
	while (temp != NULL && (temp->type == CMD_OPTION || temp->type == CMD_ARG))
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

char	**get_cmd_vector(t_token_2 *cmd_token, t_minishell *sh)
{
	int	vector_size;
	char	**cmd_vector;
	t_token_2	*temp;
	int	i;

	if (!cmd_token)
		return (NULL);
	vector_size = get_cmd_vector_size(cmd_token) + 1;
	if (vector_size <= 0)
		return (NULL);
	cmd_vector = (char **)malloc(sizeof(char *) * vector_size);
	if (!cmd_vector)
		return (NULL);
	temp = cmd_token;
	i = 1;
	cmd_vector[0] = make_exec_path(sh->path_variable, cmd_token->value); 
	temp = temp->next;
	while (temp != NULL && (temp->type == CMD_OPTION || temp->type == CMD_ARG))
	{
		cmd_vector[i] = temp->value;
		temp = temp->next;
		i++;
	}
	cmd_vector[i] = NULL;
	return (cmd_vector);
}

//chaque sub tokenList contenue dans le tokenArray represente une commande complete

void	cmdTable_add_back(cmdTable *self, t_minishell *sh, t_token_2 *cmd_token, tokenList *tklist)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		exit(EXIT_FAILURE);
	new->id = self->size;
	new->cmd_vector = get_cmd_vector(cmd_token, sh);
	new->output_type = get_effective_output_type(tklist);
	new->input_vector = io_vector_init(tklist, INPUT_REDIRECT);
	new->output_vector = io_vector_init(tklist, OUTPUT_REDIRECT);
	new->o_append_vector = io_vector_init(tklist, APPEND_REDIRECT);
	new->next = NULL;
	new->prev = NULL;
	if (self->size == 0)
	{
		self->head = new;
		self->tail = new;
	}
	else
	{
		new->prev = self->tail;
		self->tail->next = new;
		self->tail = new;
	}
	self->size += 1;
}
