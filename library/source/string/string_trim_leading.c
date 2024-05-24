/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim_leading.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:59:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 14:59:24 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*string_trim_leading_scalar(t_allocator *const allocator,
		const char *source, const int32_t scalar)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_leading_scalar(source, scalar);
	return (string_trim_left(allocator, source, amount));
}

char	*string_trim_leading_any(t_allocator *const allocator,
		const char *source, t_bitset const *delimiters)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_leading_any(source, delimiters);
	return (string_trim_left(allocator, source, amount));
}

char	*string_trim_leading_none(t_allocator *const allocator,
		const char *source, t_bitset const *delimiters)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_leading_none(source, delimiters);
	return (string_trim_left(allocator, source, amount));
}

char	*string_trim_leading_predicate(t_allocator *const allocator,
		const char *source, bool(predicate)(int32_t ch))
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_leading_predicate(source, predicate);
	return (string_trim_left(allocator, source, amount));
}

char	*string_trim_leading_sequence(t_allocator *const allocator,
		const char *haystack, const char *needle)
{
	uint64_t	amount;

	if (!haystack)
		return (NULL);
	amount = string_count_leading_sequence(haystack, needle)
		* string_length(needle);
	return (string_trim_left(allocator, haystack, amount));
}
