/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:43:26 by bifernan          #+#    #+#             */
/*   Updated: 2024/05/13 11:43:28 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	free_array(char ***array)
{
	int	i;

	i = 0;
	if (*array)
		return ;
	while (*array[i])
	{
		free(*array[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

void	print_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

int	array_len(char	**array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
