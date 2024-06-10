#include "../../header/minishell.h"


o_type	get_effective_output_type(tokenList *self)
{
	t_token_2	*temp;
	o_type	effective_type;

	if (!self)
		exit(EXIT_FAILURE);
	temp = self->head;
	effective_type = NONE;
	while (temp != NULL)
	{
		if (temp->type == OUTPUT_REDIRECT)
			effective_type = TRUNC;
		if (temp->type == APPEND_REDIRECT)
			effective_type = APPEND;
		temp = temp->next;
	}
	return (effective_type);
}
