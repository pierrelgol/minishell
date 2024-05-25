/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:39:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 13:39:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	string_contains_scalar(const char *source, const int32_t scalar,
		const uint64_t n)
{
	return (string_search_scalar(source, scalar, n) != NULL);
}

bool	string_contains_any(const char *source, t_bitset const *delimiters,
		const uint64_t n)
{
	return (string_search_any(source, delimiters, n) != NULL);
}

bool	string_contains_none(const char *source, t_bitset const *delimiters,
		const uint64_t n)
{
	return (string_search_any(source, delimiters, n) == NULL);
}

bool	string_contains_predicate(const char *source,
		bool(predicate)(int32_t ch), const uint64_t n)
{
	return (string_search_predicate(source, predicate, n) != NULL);
}

bool	string_contains_sequence(const char *haystack, const char *needle,
		const uint64_t n)
{
	return (string_search_sequence(haystack, needle, n) != NULL);
}
