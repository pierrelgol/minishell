/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_index_of_first.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:08:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 14:08:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	string_index_of_first_scalar(const char *source,
		const int32_t scalar)
{
	uint64_t	i;

	if (!source)
		return (NOTFOUND);
	i = 0;
	while (source[i])
	{
		if (source[i] == scalar)
			return (i);
		++i;
	}
	return (NOTFOUND);
}

uint64_t	string_index_of_first_any(const char *source,
		t_bitset const *delimiters)
{
	uint64_t	i;

	if (!source)
		return (NOTFOUND);
	i = 0;
	while (source[i])
	{
		if (bitset_is_set(delimiters, source[i]))
			return (i);
		++i;
	}
	return (NOTFOUND);
}

uint64_t	string_index_of_first_none(const char *source,
		t_bitset const *delimiters)
{
	uint64_t	i;

	if (!source)
		return (NOTFOUND);
	i = 0;
	while (source[i])
	{
		if (!bitset_is_set(delimiters, source[i]))
			return (i);
		++i;
	}
	return (NOTFOUND);
}

uint64_t	string_index_of_first_predicate(const char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	i;

	if (!source)
		return (NOTFOUND);
	i = 0;
	while (source[i])
	{
		if (predicate(source[i]) == true)
			return (i);
		++i;
	}
	return (NOTFOUND);
}

uint64_t	string_index_of_first_sequence(const char *haystack,
		const char *needle)
{
	uint64_t	u1;
	uint64_t	u2;

	if (!haystack)
		return (0);
	if (needle[0] == '\0')
		return (0);
	u1 = 0;
	while (haystack[u1])
	{
		u2 = 0;
		while (haystack[u1] && haystack[u1] == needle[u2])
		{
			u2++;
			u1++;
		}
		if (!needle[u2])
			return (u1 - u2);
		u1 = (u1 - u2) + 1;
	}
	return (NOTFOUND);
}
