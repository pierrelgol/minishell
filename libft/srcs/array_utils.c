/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:37:12 by bifernan          #+#    #+#             */
/*   Updated: 2024/04/05 14:37:16 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ft_deallocate_array(char **array)
{
	size_t	array_len;
	size_t	i;

	array_len = ft_arraylen(array);
	i = 0;
	while (i < array_len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

size_t	ft_arraylen(char *array[])
{
	size_t	count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}
