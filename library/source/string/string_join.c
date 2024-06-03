/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:22:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:22:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

char	*string_join(const char *const s1, const char *const s2)
{
	const uint64_t	s1len = string_length(s1);
	const uint64_t	s2len = string_length(s2);

	char *const result = memory_alloc(s1len + s2len + 1);
	if (!s1 || !s2 || !result)
		return (NULL);
	memory_copy(result, s1, s1len);
	memory_copy(result + s1len, s2, s2len);
	*(result + s1len + s2len) = 0x00;
	return (result);
}
