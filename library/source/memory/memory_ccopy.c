/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_ccopy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:16:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/03 11:17:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*memory_ccopy(void *dst, const void *src, int32_t c, uint64_t n)
{
	uint64_t		i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		if (*(s + i) == (uint8_t)c)
			return (s + i + 1);
		*(d + i) = *(s + i);
		++i;
	}
	return (0);
}
