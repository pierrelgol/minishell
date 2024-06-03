/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:17:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 10:17:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

uint64_t	string_concat(char *const dst, const char *const src,
		const uint64_t size)
{
	uint64_t	i;
	uint64_t	j;
	uint64_t	k;

	if ((!dst || !src) && !size)
		return (0);
	k = 0;
	i = string_length(dst);
	j = string_length(src);
	if (!size)
		return (j);
	k = j + i;
	if (i > size)
		return (j + size);
	j = 0;
	while (*(src + j) && i + j < size - 1)
	{
		*(dst + (i + j)) = *(src + j);
		j++;
	}
	*(dst + i + j) = '\0';
	if (k >= i + size && i > k - i)
		return (i + size);
	return (k);
}
