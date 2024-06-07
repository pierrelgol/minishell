/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:34:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 11:36:48 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

char	**split_create(const uint64_t size)
{
	char	**result;

	result = (char **)memory_alloc((size + 1) * sizeof(char **));
	if (!result)
		return (NULL);
	result[size] = NULL;
	return (result);
}

uint64_t	split_size(char **split)
{
	uint64_t	i;

	if (!split || !*split)
		return (0);
	i = 0;
	while (*(split + i))
		i += 1;
	return (i);
}

uint64_t	split_length(char **split)
{
	uint64_t	length;
	uint64_t	i;

	if (!split || !*split)
		return (0);
	i = 0;
	length = 0;
	while (*(split + i))
	{
		length += string_length(split[i]);
		i += 1;
	}
	return (length);
}

char	**split_destroy(char **split)
{
	uint64_t	i;

	if (!split || !*split)
		return (NULL);
	i = 0;
	while (*(split + i))
	{
		memory_dealloc(*(split + i));
		i += 1;
	}
	memory_dealloc(split);
	return (NULL);
}
