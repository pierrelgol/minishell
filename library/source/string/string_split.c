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

char **string_split_scalar(t_allocator *const allocator, const char *source, const int32_t scalar)
{
	char   **result;
	uint64_t size;
	uint64_t i;

	size = string_compute_scalar_split_size(source, scalar);
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (*source && *source == scalar)
			result[i++] = string_nclone(allocator, source++, 1);
		if (*source)
			result[i++] = string_clone_until_scalar(allocator, source, scalar);
		else
			break;
		while (*source && *source != scalar)
			++source;
	}
	result[i] = NULL;
	return (result);
}

char **string_split_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters)
{
	char   **result;
	uint64_t size;
	uint64_t i;

	size = string_compute_any_split_size(source, delimiters);
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (*source && bitset_is_set(delimiters, *source))
			result[i++] = string_nclone(allocator, source++, 1);
		if (*source)
			result[i++] = string_clone_until_any(allocator, source, delimiters);
		else
			break;
		while (*source && !bitset_is_set(delimiters, *source))
			++source;
	}
	result[i] = NULL;
	return (result);
}

char **string_split_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters)
{
	char   **result;
	uint64_t size;
	uint64_t i;

	size = string_compute_none_split_size(source, delimiters);
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (*source && !bitset_is_set(delimiters, *source))
			result[i++] = string_nclone(allocator, source++, 1);
		if (*source)
			result[i++] = string_clone_until_none(allocator, source, delimiters);
		else
			break;
		while (*source && bitset_is_set(delimiters, *source))
			++source;
	}
	result[i] = NULL;
	return (result);
}

char **string_split_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch))
{
	char   **result;
	uint64_t size;
	uint64_t i;

	size = string_compute_predicate_split_size(source, predicate);
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (*source && predicate(*source))
			result[i++] = string_nclone(allocator, source++, 1);
		if (*source)
			result[i++] = string_clone_until_predicate(allocator, source, predicate);
		else
			break;
		while (*source && !predicate(*source))
			++source;
	}
	result[i] = NULL;
	return (result);
}

char **string_split_sequence(t_allocator *const allocator, const char *haystack, const char *needle)
{
	char   **result;
	uint64_t len;
	uint64_t nlen;
	uint64_t i;
	uint64_t j;

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
			result[i] = string_substring_sequence(allocator, &haystack[j], needle);
		j += string_length(result[i++]);
	}
	return (result);
}
