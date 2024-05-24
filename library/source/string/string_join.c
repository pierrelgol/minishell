/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:34:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 12:34:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*string_join_scalar(t_allocator *const allocator, const char *string,
		const int32_t scalar)
{
	char		*result;
	uint64_t	len;

	len = string_length(string) + 1;
	result = allocator->create(allocator, len + 1);
	result = string_append_sequence(result, string, len + 1);
	result = string_append_scalar(result, scalar, len + 1);
	return (result);
}

char	*string_join_sequence(t_allocator *const allocator, const char *string,
		const char *sequence)
{
	char		*result;
	uint64_t	len;

	len = string_length(string) + string_length(sequence);
	result = allocator->create(allocator, len + 1);
	result = string_append_sequence(result, string, len + 1);
	result = string_append_sequence(result, sequence, len + 1);
	return (result);
}

char	*string_join_scalar_sequence(t_allocator *const allocator,
		const char *string, const int32_t scalar, const char *sequence)
{
	char		*result;
	uint64_t	len;

	len = string_length(string) + string_length(sequence) + 1;
	result = allocator->create(allocator, len + 1);
	result = string_append_sequence(result, string, len + 1);
	result = string_append_scalar(result, scalar, len + 1);
	result = string_append_sequence(result, sequence, len + 1);
	return (result);
}

char	*string_join_many_sequence(t_allocator *const allocator,
		const char *string, const char **many)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	len = string_split_length(many);
	result = allocator->create(allocator, len + 1);
	i = 0;
	string_append_sequence(result, string, len + 1);
	while (many[i])
		string_append_sequence(result, many[i++], len + 1);
	return (result);
}

char	*string_join_many_scalar_sequence(t_allocator *const allocator,
		const char *string, const int32_t scalar, const char **many)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	len = string_split_length(many);
	result = allocator->create(allocator, len + 1);
	i = 0;
	string_append_sequence(result, string, len + 1);
	while (many[i])
	{
		string_append_scalar(result, scalar, len + 1);
		string_append_sequence(result, many[i++], len + 1);
	}
	return (result);
}
