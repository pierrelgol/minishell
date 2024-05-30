#include "../minishell.h"

void	handle_first_token(t_token *self)
{
	if (self->id == 0)
	{
		if (self->type != INPUT_REDIRECT && self->type != OUTPUT_REDIRECT && self->type != APPEND_REDIRECT \
				&& self->type != HERE_DOC)
			self->type = CMD;
	}
}

void	guesser(t_minishell *sh) //mettre les bons types et verifier la syntaxe 
{
	t_token	*token;
	
	if (!sh || !sh->token_list)
		return ;
	token = sh->token_list->head;

	//mettre les bons types
	while (token != NULL) //on va chercher une commande valide
	{

		handle_first_token(token);	
		if (token->type == IDENTIFIER || token->type == PATH) //tester si un IDENTIFIER est une commande
		{
			if (test_if_executable(sh, token))
				token->type = CMD;
		}
		if (token->type == GUESS_FILE || token->type == PATH || token->type == UNKNOWN)
		{
			if (access(token->value, F_OK) == 0)
				token->type = EXISTING_FILE;
		}
		if (token->id != 0)
		{
			if (token->prev->type == PIPE)
				token->type = CMD;
			if (token->prev->type == HERE_DOC)
				token->type = HD_DELIM;
			if ((token->prev->type == CMD || token->prev->type == CMD_OPTION || token->prev->type == CMD_ARG) \
			&& (token->type == GUESS_FILE || token->type == IDENTIFIER || token->type == CMD || token->type == UNKNOWN || token->type == EXISTING_FILE || token->type == UNEXISTING_FILE) && token->type != CMD_OPTION)
				token->type = CMD_ARG;
			if (token->prev->type == OUTPUT_REDIRECT || token->prev->type == APPEND_REDIRECT || token->prev->type == INPUT_REDIRECT)
			{
				if (access(token->value, F_OK) == 0)
					token->type = EXISTING_FILE;
				else
					token->type = UNEXISTING_FILE;
			}
		}
		token = token->next;
	}
}
