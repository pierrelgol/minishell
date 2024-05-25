/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:44:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 12:44:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	string_copy_until_scalar(char *dest, const char *src,
		const int32_t scalar, const uint64_t destsize)
{
	uint64_t	i;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	while (*src && i < (destsize - 1))
	{
		if (*src == scalar)
			break ;
		dest[i++] = *src++;
	}
	dest[i] = 0x00;
	return (i);
}

uint64_t	string_copy_until_any(char *dest, const char *src,
		const t_bitset *delimiters, const uint64_t destsize)
{
	uint64_t	i;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	while (*src && i < (destsize - 1))
	{
		if (bitset_is_set(delimiters, *src))
			break ;
		dest[i++] = *src++;
	}
	dest[i] = 0x00;
	return (i);
}

uint64_t	string_copy_until_none(char *dest, const char *src,
		const t_bitset *delimiters, const uint64_t destsize)
{
	uint64_t	i;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	while (*src && i < (destsize - 1))
	{
		if (!bitset_is_set(delimiters, *src))
			break ;
		dest[i++] = *src++;
	}
	dest[i] = 0x00;
	return (i);
}

uint64_t	string_copy_until_predicate(char *dest, const char *src,
		bool(predicate)(int32_t ch), const uint64_t destsize)
{
	uint64_t	i;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	while (*src && i < (destsize - 1))
	{
		if (predicate(*src))
			break ;
		dest[i++] = *src++;
	}
	dest[i] = 0x00;
	return (i);
}

uint64_t	string_copy_until_sequence(char *dest, const char *src,
		const char *needle, const uint64_t destsize)
{
	uint64_t	i;
	char		*end;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	end = string_search_sequence(src, needle, string_length(src));
	if (!end)
		return (string_copy_until_scalar(dest, src, '\0', destsize));
	else
	{
		while (src < end && i < (destsize - 1))
			dest[i++] = *src++;
		dest[i] = 0x00;
	}
	return (i);
}
