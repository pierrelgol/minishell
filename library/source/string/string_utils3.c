/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:38:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 19:38:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char **string_split_get_split_buffer_scalar(t_allocator *const allcator, const char *source, const int32_t scalar, uint64_t *out_size)
{
	char   **result;
	uint64_t count;
	uint64_t i;

	count = string_count_scalar(source, scalar, string_length(source));
	i = 0;
	while (source[i])
	{
		while (source[i] && source[i] == scalar)
			++i;
		count += 1;
		while (source[i] && source[i] != scalar)
			++i;
	}
	result = allcator->create(allcator, (count + 1) *sizeof(char *));
	*out_size = count;
	return (result);
}

char **string_split_get_split_buffer_any(t_allocator *const allcator, const char *source, const t_bitset *any, uint64_t *out_size)
{
	char   **result;
	uint64_t count;
	uint64_t i;

	count = string_count_any(source, any, string_length(source));
	i = 0;
	while (source[i])
	{
		while (source[i] && bitset_is_set(any, source[i]))
			++i;
		count += 1;
		while (source[i] && !bitset_is_set(any, source[i]))
			++i;
	}
	result = allcator->create(allcator, (count + 1) *sizeof(char *));
	*out_size = count;
	return (result);
}


char **string_split_get_split_buffer_none(t_allocator *const allcator, const char *source, const t_bitset *none, uint64_t *out_size)
{
	char   **result;
	uint64_t count;
	uint64_t i;

	count = string_count_none(source, none, string_length(source));
	i = 0;
	while (source[i])
	{
		while (source[i] && !bitset_is_set(none, source[i]))
			++i;
		count += 1;
		while (source[i] && bitset_is_set(none, source[i]))
			++i;
	}
	result = allcator->create(allcator, (count + 1) *sizeof(char *));
	*out_size = count;
	return (result);
}

char **string_split_get_split_buffer_predicate(t_allocator *const allcator, const char *source, bool (*predicate)(int32_t), uint64_t *out_size)
{
	char   **result;
	uint64_t count;
	uint64_t i;

	count = string_count_predicate(source, predicate, string_length(source));
	i = 0;
	while (source[i])
	{
		while (source[i] && predicate(source[i]))
			++i;
		count += 1;
		while (source[i] && !predicate(source[i]))
			++i;
	}
	result = allcator->create(allcator, (count + 1) *sizeof(char *));
	*out_size = count;
	return (result);
}
