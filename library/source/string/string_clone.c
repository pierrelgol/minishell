/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:29:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 13:29:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

char	*string_clone(t_allocator *const allocator, const char *src)
{
	return (string_nclone(allocator, src, string_length(src)));
}

char	*string_clone_scalar(t_allocator *const allocator, const int32_t ch)
{
	char	*result;

	result = allocator->create(allocator, 2);
	result[0] = (uint8_t)ch;
	result[1] = 0x00;
	return (result);
}

char	*string_nclone(t_allocator *const allocator, const char *src,
		uint64_t n)
{
	char	*result;

	result = allocator->create(allocator, n + 1);
	result = string_append_sequence(result, src, n + 1);
	return (result);
}
