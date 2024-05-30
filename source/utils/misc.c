/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:57 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:31:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

bool from_string_to_key_value_pair(t_allocator *allocator, char *source, char **key, char **value)
{
	*key = string_clone_until_scalar(allocator, source, '=');
	*value = string_trim_left(allocator, source, string_index_of_first_scalar(source, '=') + 1);
	return (true);
}

bool is_identifier_start(int32_t ch)
{
	return (is_alpha(ch) || ch == '_');
}

bool is_identifier(int32_t ch)
{
	return (is_alnum(ch) || ch == '_');
}

bool is_path(const char *str)
{
	t_bitset start;
	t_bitset inside;

	start = bitset_init_from_str("/~.");
	inside = bitset_set_bit_range(&inside, ALNUM);
	inside = bitset_set_bit_range(&inside, "/.");
	if (string_starts_with_any(str, &start))
	{
		if (string_is_all_any(&str[1], &inside))
			return (true);
	}
	return false;
}

bool is_file(const char *str)
{
	if (string_contains_scalar(str, '.', string_length(str)))
		return (true);
	return (false);
}

int32_t key_compare(uintptr_t k1, uintptr_t k2)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *) k1;
	p2 = (unsigned char *) k2;
	while (*p1 && *p1 == *p2)
	{
		++p1;
		++p2;
	}
	return (*p1 - *p2);
}
