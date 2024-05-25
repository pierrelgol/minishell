/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone_until.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:08:09 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 12:08:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*string_clone_until_scalar(t_allocator *const allocator,
		const char *src, const int32_t scalar)
{
	char		*result;
	uint64_t	len;

	len = string_count_until_scalar(src, scalar);
	result = allocator->create(allocator, len + 1);
	string_copy_until_scalar(result, src, scalar, len + 1);
	return (result);
}

char	*string_clone_until_any(t_allocator *const allocator, const char *src,
		const t_bitset *delimiters)
{
	char		*result;
	uint64_t	len;

	len = string_count_until_any(src, delimiters);
	result = allocator->create(allocator, len + 1);
	string_copy_until_any(result, src, delimiters, len + 1);
	return (result);
}

char	*string_clone_until_none(t_allocator *const allocator, const char *src,
		const t_bitset *delimiters)
{
	char		*result;
	uint64_t	len;

	len = string_count_until_none(src, delimiters);
	result = allocator->create(allocator, len + 1);
	string_copy_until_none(result, src, delimiters, len + 1);
	return (result);
}

char	*string_clone_until_predicate(t_allocator *const allocator,
		const char *src, bool(predicate)(int32_t ch))
{
	char		*result;
	uint64_t	len;

	len = string_count_until_predicate(src, predicate);
	result = allocator->create(allocator, len + 1);
	string_copy_until_predicate(result, src, predicate, len + 1);
	return (result);
}

char	*string_clone_until_sequence(t_allocator *const allocator,
		const char *src, const char *needle)
{
	char		*result;
	uint64_t	len;

	len = string_count_until_sequence(src, needle);
	result = allocator->create(allocator, len + 1);
	string_copy_until_sequence(result, src, needle, len + 1);
	return (result);
}
