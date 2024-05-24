/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_substring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:13:57 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 12:13:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*string_substring_scalar(t_allocator *const allocator, const char *src,
		const int32_t scalar)
{
	char	*result;

	src += string_count_leading_scalar(src, scalar);
	result = string_clone_until_scalar(allocator, src, scalar);
	return (result);
}

char	*string_substring_any(t_allocator *const allocator, const char *src,
		const t_bitset *delimiters)
{
	char	*result;

	src += string_count_leading_any(src, delimiters);
	result = string_clone_until_any(allocator, src, delimiters);
	return (result);
}

char	*string_substring_none(t_allocator *const allocator, const char *src,
		const t_bitset *delimiters)
{
	char	*result;

	src += string_count_leading_none(src, delimiters);
	result = string_clone_until_none(allocator, src, delimiters);
	return (result);
}

char	*string_substring_predicate(t_allocator *const allocator,
		const char *src, bool(predicate)(int32_t ch))
{
	char	*result;

	src += string_count_leading_predicate(src, predicate);
	result = string_clone_until_predicate(allocator, src, predicate);
	return (result);
}

char	*string_substring_sequence(t_allocator *const allocator,
		const char *src, const char *needle)
{
	char	*result;

	src += string_count_leading_sequence(src, needle) * string_length(needle);
	result = string_clone_until_sequence(allocator, src, needle);
	return (result);
}
