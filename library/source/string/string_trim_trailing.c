/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim_trailing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:22:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 15:22:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*string_trim_trailing_scalar(t_allocator *const allocator,
		const char *source, const int32_t scalar)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_trailing_scalar(source, scalar);
	return (string_trim_right(allocator, source, amount));
}

char	*string_trim_trailing_any(t_allocator *const allocator,
		const char *source, t_bitset const *delimiters)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_trailing_any(source, delimiters);
	return (string_trim_right(allocator, source, amount));
}

char	*string_trim_trailing_none(t_allocator *const allocator,
		const char *source, t_bitset const *delimiters)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_trailing_none(source, delimiters);
	return (string_trim_right(allocator, source, amount));
}

char	*string_trim_trailing_predicate(t_allocator *const allocator,
		const char *source, bool(predicate)(int32_t ch))
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_trailing_predicate(source, predicate);
	return (string_trim_right(allocator, source, amount));
}

char	*string_trim_trailing_sequence(t_allocator *const allocator,
		const char *haystack, const char *needle)
{
	uint64_t	amount;

	if (!haystack)
		return (NULL);
	amount = string_length(needle) * string_count_trailing_sequence(haystack,
			needle);
	return (string_trim_right(allocator, haystack, amount));
}
