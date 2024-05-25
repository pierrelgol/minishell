/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:25:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/03 11:25:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

int32_t	memory_compare(const void *s1, const void *s2, uint64_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	uint64_t		i;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*(p1 + i) != *(p2 + i))
			return (*(p1 + i) - *(p2 + i));
		++i;
	}
	return (0);
}
