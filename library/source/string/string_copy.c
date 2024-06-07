/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:14:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 10:14:21 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

uint64_t	string_copy(char *const dest, const char *const source,
		const uint64_t dsize)
{
	const uint64_t	slen = string_length(source);
	uint64_t		i;

	if (dsize == 0)
		return (slen);
	i = 0;
	while (*(source + i) && (i + 1) < dsize)
	{
		*(dest + i) = *(source + i);
		i += 1;
	}
	*(dest + i) = '\0';
	return (slen);
}
