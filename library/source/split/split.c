/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:43:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 11:43:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static bool	contains(const char *set, const uint64_t ch)
{
	return (set[ch] == 1);
}

static char	*make_word(const char **source, const char *set)
{
	const char	*ptr;
	char		*word;

	if (contains(set, *(*source)))
	{
		word = string_nclone(*source, 1);
		(*source) += 1;
	}
	else
	{
		ptr = *source;
		while (*ptr && !contains(set, *ptr))
			++ptr;
		word = string_nclone(*source, (ptr - (*source)));
		(*source) += (ptr - (*source));
	}
	return (word);
}

static char	*make_set(char *set, const char *delimiters)
{
	uint64_t	i;

	i = 0;
	while (*(delimiters + i))
	{
		set[(uint64_t) * (delimiters + i)] = 1;
		i += 1;
	}
	return (set);
}

char	**split(const char *source, const char *delimiters)
{
	char		**result;
	char		*set;
	uint64_t	size;
	uint64_t	i;

	if (!source || !delimiters)
		return (NULL);
	set = (char[256]){0};
	set = make_set(set, delimiters);
	size = string_wcount(source, delimiters) + string_count(source, delimiters);
	result = split_create(size);
	i = 0;
	while (*source)
	{
		result[i] = make_word(&source, set);
		if (!result[i])
			return (split_destroy(result));
		i += 1;
	}
	result[i] = NULL;
	return (result);
}
