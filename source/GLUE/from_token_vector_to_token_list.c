/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_token_vector_to_token_list.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:45:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/10 14:45:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	from_token_vector_to_token_list(t_shell *shell ,t_minishell *minishell, t_vector *token_vector)
{
	t_token	*token;

	(void)shell;
	it_save(token_vector);
	while (!it_end(token_vector))
	{
		token = (t_token*)it_peek_curr(token_vector);
		if (token)
			token_list_add_back(minishell->token_list, token);
		it_advance(token_vector);
	}
	it_restore(token_vector);
}

