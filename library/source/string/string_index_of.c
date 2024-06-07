/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:21:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 10:21:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

int64_t	string_index_of(const char *const source, const int32_t ch)
{
	const uint64_t	slen = string_length(source);

	const char *const result = memory_search(source, ch, slen);
	if (!result)
		return (-1);
	return (result - source);
}

// int64_t	string_index_of(const char *const source, const int32_t ch)
// {
// 	const uint64_t		slen = string_length(source);
// 	const char *const	elem = (const char [2]){ch, 0x00};
// 	const char *const	result = string_search(source, elem, slen);

// 	if (!result)
// 		return (-1);
// 	return (result - source);
// }
