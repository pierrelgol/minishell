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
	uint64_t j;

	size = string_compute_scalar_split_size(source, scalar);
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (j < size && source[i])
	{
		while (source[i] && source[i] == scalar)
			result[j++] = string_nclone(allocator, &source[i++], 1);
		if (source[i] != '\0')
			result[j++] = string_substring_scalar(allocator, &source[i], scalar);
		else
			break;
		while (source[i] && source[i] != scalar)
			++i;
	}
	result[j] = NULL;
	return (result);
}

char **string_split_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters)
{
	char   **result;
	uint64_t size;
	uint64_t i;
	uint64_t j;

	size = string_compute_any_split_size(source, delimiters);
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (j < size && source[i])
	{
		while (source[i] && bitset_is_set(delimiters, source[i]))
			result[j++] = string_nclone(allocator, &source[i++], 1);
		if (source[i] != '\0')
			result[j++] = string_substring_any(allocator, &source[i], delimiters);
		else
			break;
		while (source[i] && !bitset_is_set(delimiters, source[i]))
			++i;
	}
	result[i] = NULL;
	return (result);
}

char **string_split_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters)
{
	char   **result;
	uint64_t size;
	uint64_t i;
	uint64_t j;

	size = string_compute_none_split_size(source, delimiters);
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (j < size && source[i])
	{
		while (source[i] && !bitset_is_set(delimiters, source[i]))
			result[j++] = string_nclone(allocator, &source[i++], 1);
		if (source[i] != '\0')
			result[j++] = string_substring_none(allocator, &source[i], delimiters);
		else
			break;
		while (source[i] && bitset_is_set(delimiters, source[i]))
			++i;
	}
	result[i] = NULL;
	return (result);
}

char **string_split_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch))
{	char   **result;
	uint64_t size;
	uint64_t i;
	uint64_t j;

	size = string_compute_predicate_split_size(source, predicate);
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (j < size && source[i])
	{
		while (source[i] && predicate(source[i]))
			result[j++] = string_nclone(allocator, &source[i++], 1);
		if (source[i] != '\0')
			result[j++] = string_substring_predicate(allocator, &source[i], predicate);
		else
			break;
		while (source[i] && !predicate(source[i]))
			++i;
	}
	result[j] = NULL;
	return (result);
}

char **string_split_sequence(t_allocator *const allocator, const char *haystack, const char *needle)
{
	char   **result;
	uint64_t size;
	uint64_t nlen;
	uint64_t i;
	uint64_t j;

	nlen = string_length(needle);
	size = string_wcount_sequence(haystack, needle);
	size += string_count_sequence(haystack, needle, string_length(haystack));
	result = allocator->create(allocator, (size + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < size && haystack[j])
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
