/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:03:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 13:03:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t string_compute_scalar_split_size(const char *source, const int32_t scalar)
{
	uint64_t scalar_count;
	uint64_t word_count;

	scalar_count = 0;
	word_count = 0;
	while (*source)
	{
		while (*source && *source == scalar)
		{
			++scalar_count;
			++source;
		}
		if (*source)
			++word_count;
		while (*source && *source != scalar)
			++source;
	}
	return (scalar_count + word_count);
}

uint64_t string_compute_any_split_size(const char *source, t_bitset const *delimiters)
{
	uint64_t any_count;
	uint64_t word_count;

	any_count = 0;
	word_count = 0;
	while (*source)
	{
		while (*source && bitset_is_set(delimiters, *source))
		{
			++any_count;
			++source;
		}
		if (*source)
			++word_count;
		while (*source && !bitset_is_set(delimiters, *source))
			++source;
	}
	return (any_count + word_count);
}

uint64_t string_compute_none_split_size(const char *source, t_bitset const *delimiters)
{
	uint64_t none_count;
	uint64_t word_count;

	none_count = 0;
	word_count = 0;
	while (*source)
	{
		while (*source && !bitset_is_set(delimiters, *source))
		{
			++none_count;
			++source;
		}
		if (*source)
			++word_count;
		while (*source && bitset_is_set(delimiters, *source))
			++source;
	}
	return (none_count + word_count);
}

uint64_t string_compute_predicate_split_size(const char *source, bool (predicate)(int32_t ch))
{
	uint64_t predicate_count;
	uint64_t word_count;

	predicate_count = 0;
	word_count = 0;
	while (*source)
	{
		while (*source && predicate(*source))
		{
			++predicate_count;
			++source;
		}
		if (*source)
			++word_count;
		while (*source && !predicate(*source))
			++source;
	}
	return (predicate_count + word_count);
}

uint64_t string_compute_sequence_split_size(const char *source, const char *needle)
{
	uint64_t sequence_count;
	uint64_t word_count;
	uint64_t nlen;
	uint64_t slen;
	uint64_t i;

	i = 0;
	word_count = 0;
	sequence_count = 0;
	nlen = string_length(needle);
	slen = string_length(source);
	while (source[i])
	{
		while (i < slen && string_starts_with_sequence(&source[i], needle))
		{
			++sequence_count;
			i += nlen;
		}
		if (source[i])
			++word_count;
		while (i < slen && !string_starts_with_sequence(&source[i], needle))
			++i;
	}
	return (sequence_count + word_count);
}
