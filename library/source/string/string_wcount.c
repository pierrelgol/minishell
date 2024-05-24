/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_wcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:18:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/10 12:18:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	string_wcount_scalar(const char *source, const int32_t scalar)
{
	uint64_t	count;
	uint64_t	slen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	count = 0;
	slen = string_length(source);
	while (i < slen)
	{
		i += string_count_leading_scalar(&source[i], scalar);
		if (i < slen)
			count += 1;
		i += string_count_until_scalar(&source[i], scalar);
	}
	return (count);
}

uint64_t	string_wcount_any(const char *source, const t_bitset *delimiters)
{
	uint64_t	count;
	uint64_t	slen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	count = 0;
	slen = string_length(source);
	while (i < slen)
	{
		i += string_count_leading_any(&source[i], delimiters);
		if (i < slen)
			count += 1;
		i += string_count_until_any(&source[i], delimiters);
	}
	return (count);
}

uint64_t	string_wcount_none(const char *source, const t_bitset *delimiters)
{
	uint64_t	count;
	uint64_t	slen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	count = 0;
	slen = string_length(source);
	while (i < slen)
	{
		i += string_count_leading_none(&source[i], delimiters);
		if (i < slen)
			count += 1;
		i += string_count_until_none(&source[i], delimiters);
	}
	return (count);
}

uint64_t	string_wcount_predicate(const char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	count;
	uint64_t	slen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	count = 0;
	slen = string_length(source);
	while (i < slen)
	{
		i += string_count_leading_predicate(&source[i], predicate);
		if (i < slen)
			count += 1;
		i += string_count_until_predicate(&source[i], predicate);
	}
	return (count);
}

uint64_t	string_wcount_sequence(const char *source, const char *needle)
{
	uint64_t	count;
	uint64_t	slen;
	uint64_t	nlen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	count = 0;
	nlen = string_length(needle);
	slen = string_length(source);
	while (i < slen)
	{
		i += (nlen * string_count_leading_sequence(&source[i], needle));
		if (i < slen)
			count += 1;
		i += string_count_until_sequence(&source[i], needle);
	}
	return (count);
}
