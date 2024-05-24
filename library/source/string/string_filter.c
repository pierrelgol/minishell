/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:34:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 15:34:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*string_filter_scalar(t_allocator *const allocator, const char *source,
		const int32_t scalar)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	if (!source)
		return (NULL);
	len = string_length(source);
	len -= string_count_scalar(source, scalar, len);
	result = allocator->create(allocator, len + 1);
	i = 0;
	while (*source && i < len)
	{
		if (*source == scalar)
			++source;
		else
			result[i++] = *source++;
	}
	return (result);
}

char	*string_filter_any(t_allocator *const allocator, const char *source,
		t_bitset const *delimiters)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	if (!source)
		return (NULL);
	len = string_length(source);
	len -= string_count_any(source, delimiters, len);
	result = allocator->create(allocator, len + 1);
	i = 0;
	while (*source && i < len)
	{
		if (bitset_is_set(delimiters, *source))
			++source;
		else
			result[i++] = *source++;
	}
	return (result);
}

char	*string_filter_none(t_allocator *const allocator, const char *source,
		t_bitset const *delimiters)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	if (!source)
		return (NULL);
	len = string_length(source);
	len -= string_count_none(source, delimiters, len);
	result = allocator->create(allocator, len + 1);
	i = 0;
	while (*source && i < len)
	{
		if (!bitset_is_set(delimiters, *source))
			++source;
		else
			result[i++] = *source++;
	}
	return (result);
}

char	*string_filter_predicate(t_allocator *const allocator,
		const char *source, bool(predicate)(int32_t ch))
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	if (!source)
		return (NULL);
	len = string_length(source);
	len -= string_count_predicate(source, predicate, len);
	result = allocator->create(allocator, len + 1);
	i = 0;
	while (*source && i < len)
	{
		if (predicate(*source))
			++source;
		else
			result[i++] = *source++;
	}
	return (result);
}

char	*string_filter_sequence(t_allocator *const allocator,
		const char *haystack, const char *needle)
{
	char		*result;
	char		*end;
	uint64_t	nlen;
	uint64_t	rlen;
	uint64_t	i;

	if (!haystack)
		return (NULL);
	if (!needle || !needle[0])
		return (string_clone(allocator, (void *const)haystack));
	end = (char *)haystack + string_length(haystack);
	rlen = (uint64_t)(end - haystack);
	nlen = string_length(needle);
	rlen -= (string_count_sequence(haystack, needle, rlen) * nlen);
	result = allocator->create(allocator, rlen + 1);
	i = 0;
	while (haystack <= end && i < rlen)
	{
		if (string_index_of_difference(needle, haystack) == nlen)
			haystack += nlen;
		else
			result[i++] = *haystack++;
	}
	return (result);
}
