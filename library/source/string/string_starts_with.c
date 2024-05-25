/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_starts_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:47:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 13:47:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	string_starts_with_scalar(const char *source, const int32_t scalar)
{
	if (!source)
		return (false);
	return (source[0] == scalar);
}

bool	string_starts_with_any(const char *source, t_bitset const *delimiters)
{
	if (!source)
		return (false);
	return (bitset_is_set(delimiters, source[0]) == true);
}

bool	string_starts_with_none(const char *source, t_bitset const *delimiters)
{
	if (!source)
		return (false);
	return (bitset_is_set(delimiters, source[0]) == false);
}

bool	string_starts_with_predicate(const char *source,
		bool(predicate)(int32_t ch))
{
	if (!source)
		return (false);
	return (predicate(source[0]) == true);
}

bool	string_starts_with_sequence(const char *haystack, const char *needle)
{
	if (!haystack || !needle)
		return (false);
	return (string_search_sequence(haystack, needle, string_length(needle)));
}
