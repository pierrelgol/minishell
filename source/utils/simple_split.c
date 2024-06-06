/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:10:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/06 13:10:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint64_t string_count_words(const char *const source, const int32_t ch)
{
	uint64_t count = 0;
	uint64_t i = 0;

	if (!source)
		return 0;

	while (source[i])
	{
		while (source[i] && source[i] == ch)
			++i;
		if (source[i])
			++count;
		while (source[i] && source[i] != ch)
			++i;
	}
	return count;
}

char **simple_split(const char *const source, const int32_t ch)
{
	char   **result;
	uint64_t size;
	uint64_t start;
	uint64_t end;
	uint64_t i;

	if (!source)
		return (NULL);
	size = string_count_words(source, ch);
	result = split_create(size);
	if (!result)
		return (NULL);
	start = 0;
	i = 0;
	while (source[start])
	{
		start += string_span(&source[start], (char[2]){ch, 0x00});
		if (source[start] == '\0')
			break;

		end = string_cspan(&source[start], (char[2]){ch, 0x00});
		result[i] = string_nclone(&source[start], end);
		if (!result[i])
		{
			split_destroy(result);
			return NULL;
		}
		++i;
		start += end;
	}
	result[i] = NULL;
	return result;
}
