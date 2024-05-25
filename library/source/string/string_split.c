/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:04:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 13:04:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	**string_split_scalar(t_allocator *const allocator, const char *source,
		const int32_t scalar)
{
	char		**result;
	uint64_t	len;
	uint64_t	i;
	uint64_t	j;

	if (!source)
		return (NULL);
	len = string_wcount_scalar(source, scalar) + string_count_scalar(source,
			scalar, string_length(source));
	result = allocator->create(allocator, (len + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < len)
	{
		while (source[j] && source[j] == scalar)
			result[i++] = string_clone_scalar(allocator, source[j++]);
		if (source[j])
			result[i] = string_substring_scalar(allocator, &source[j], scalar);
		j += string_length(result[i]);
		i += 1;
	}
	result[i] = NULL;
	return (result);
}

char	**string_split_any(t_allocator *const allocator, const char *source,
		t_bitset const *delimiters)
{
	char		**result;
	uint64_t	len;
	uint64_t	i;
	uint64_t	j;

	if (!source)
		return (NULL);
	len = string_wcount_any(source, delimiters) + string_count_any(source,
			delimiters, string_length(source));
	result = allocator->create(allocator, (len + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < len)
	{
		while (source[j] && bitset_is_set(delimiters, source[j]))
			result[i++] = string_clone_scalar(allocator, source[j++]);
		if (source[j])
			result[i] = string_substring_any(allocator, &source[j], delimiters);
		j += string_length(result[i]);
		i += 1;
	}
	result[i] = NULL;
	return (result);
}

char	**string_split_none(t_allocator *const allocator, const char *source,
		t_bitset const *delimiters)
{
	char		**result;
	uint64_t	len;
	uint64_t	i;
	uint64_t	j;

	if (!source)
		return (NULL);
	len = string_wcount_none(source, delimiters) + string_count_none(source,
			delimiters, string_length(source));
	result = allocator->create(allocator, (len + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < len)
	{
		while (source[j] && bitset_is_set(delimiters, source[j]))
			result[i++] = string_clone_scalar(allocator, source[j++]);
		if (source[j])
			result[i] = string_substring_none(allocator, &source[j],
					delimiters);
		j += string_length(result[i]);
		i += 1;
	}
	result[i] = NULL;
	return (result);
}

char	**string_split_predicate(t_allocator *const allocator,
		const char *source, bool(predicate)(int32_t ch))
{
	char		**result;
	uint64_t	len;
	uint64_t	i;
	uint64_t	j;

	if (!source)
		return (NULL);
	len = string_wcount_predicate(source, predicate)
		+ string_count_predicate(source, predicate, string_length(source));
	result = allocator->create(allocator, (len + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < len)
	{
		while (source[j] && predicate(source[j]))
			result[i++] = string_clone_scalar(allocator, source[j++]);
		if (source[j])
			result[i] = string_substring_predicate(allocator, &source[j],
					predicate);
		j += string_length(result[i]);
		i += 1;
	}
	result[i] = NULL;
	return (result);
}

char	**string_split_sequence(t_allocator *const allocator,
		const char *haystack, const char *needle)
{
	char		**result;
	uint64_t	len;
	uint64_t	nlen;
	uint64_t	i;
	uint64_t	j;

	nlen = string_length(needle);
	len = string_wcount_sequence(haystack, needle);
	len += string_count_sequence(haystack, needle, string_length(haystack));
	result = allocator->create(allocator, (len + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < len)
	{
		while (haystack[j] && string_starts_with_sequence(&haystack[j], needle))
		{
			result[i++] = string_clone(allocator, needle);
			j += nlen;
		}
		if (haystack[j])
			result[i] = string_substring_sequence(allocator, &haystack[j],
					needle);
		j += string_length(result[i++]);
	}
	return (result);
}
