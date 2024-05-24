/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:27:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 14:27:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	string_count_scalar(const char *source, const int32_t scalar,
		const uint64_t n)
{
	uint64_t	count;
	uint64_t	i;

	if (!source || !n)
		return (0);
	i = 0;
	count = 0;
	while (source[i] && i < n)
	{
		if (source[i] == scalar)
			count += 1;
		++i;
	}
	return (count);
}

uint64_t	string_count_any(const char *source, t_bitset const *delimiters,
		const uint64_t n)
{
	uint64_t	count;
	uint64_t	i;

	if (!source || !n)
		return (0);
	i = 0;
	count = 0;
	while (source[i] && i < n)
	{
		if (bitset_is_set(delimiters, source[i]))
			count += 1;
		++i;
	}
	return (count);
}

uint64_t	string_count_none(const char *source, t_bitset const *delimiters,
		const uint64_t n)
{
	uint64_t	count;
	uint64_t	i;

	if (!source || !n)
		return (0);
	i = 0;
	count = 0;
	while (source[i] && i < n)
	{
		if (!bitset_is_set(delimiters, source[i]))
			count += 1;
		++i;
	}
	return (count);
}

uint64_t	string_count_predicate(const char *source,
		bool(predicate)(int32_t ch), const uint64_t n)
{
	uint64_t	count;
	uint64_t	i;

	if (!source || !n)
		return (0);
	i = 0;
	count = 0;
	while (source[i] && i < n)
	{
		if (predicate(source[i]))
			count += 1;
		++i;
	}
	return (count);
}

uint64_t	string_count_sequence(const char *haystack, const char *needle,
		const uint64_t n)
{
	uint64_t	u1;
	uint64_t	u2;
	uint64_t	count;

	if (!haystack)
		return (0);
	if (needle[0] == '\0')
		return (0);
	u1 = 0;
	count = 0;
	while (haystack[u1])
	{
		u2 = 0;
		while (haystack[u1] && haystack[u1] == needle[u2] && u1 < n)
		{
			u2++;
			u1++;
		}
		if (!needle[u2])
			count += 1;
		u1 = (u1 - u2) + 1;
	}
	return (count);
}
