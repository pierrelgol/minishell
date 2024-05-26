/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_is_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:11:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 13:11:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool string_is_all_scalar(const char *source, const int32_t scalar)
{
	uint64_t i;

	i = 0;
	while (source[i])
	{
		if (source[i] != scalar)
			return (false);
		++i;
	}
	return (true);
}

bool string_is_all_any(const char *source, t_bitset const *any)
{
	uint64_t i;

	i = 0;
	while (source[i])
	{
		if (!bitset_is_set(any, source[i]))
			return (false);
		++i;
	}
	return (true);
}

bool string_is_all_none(const char *source, t_bitset const *none)
{
	uint64_t i;

	i = 0;
	while (source[i])
	{
		if (bitset_is_set(none, source[i]))
			return (false);
		++i;
	}
	return (true);
}

bool string_is_all_predicate(const char *source, bool (predicate)(int32_t ch))
{
	uint64_t i;

	i = 0;
	while (source[i])
	{
		if (!predicate(source[i]))
			return (false);
		++i;
	}
	return (true);
}

bool string_is_all_sequence(const char *source, const char *sequence)
{
	return (string_compare(source, sequence) == 0);
}
