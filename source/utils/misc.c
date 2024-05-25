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
