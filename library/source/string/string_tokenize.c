/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tokenize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:59:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/21 10:59:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char *string_tokenize_scalar(t_allocator *const allocator, const char *source, const int32_t scalar, const int32_t marker)
{
	char *result;

	result = string_replace_scalar(allocator, source, scalar, marker);
	return (result);
}

char *string_tokenize_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters, const int32_t marker)
{
	char *result;

	result = string_replace_any(allocator, source, delimiters, marker);
	return (result);
}

char *string_tokenize_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters, const int32_t marker)
{
	char *result;

	result = string_replace_none(allocator, source, delimiters, marker);
	return (result);
}

char *string_tokenize_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch), const int32_t marker)
{
	char *result;

	result = string_replace_predicate(allocator, source, predicate, marker);
	return (result);
}

char *string_tokenize_sequence(t_allocator *const allocator, const char *haystack, const char *needle, const int32_t marker)
{
	char *result;
	char  temp[2];

	temp[0] = marker;
	temp[1] = 0x00;
	result = allocator->create(allocator, string_compute_replace_sequence_size(haystack, needle, temp) + 1);
	result = string_replace_sequence(haystack, needle, temp, result);
	return (result);
}
