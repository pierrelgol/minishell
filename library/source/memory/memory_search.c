/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:30:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/03 11:30:13 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*memory_search(const void *src, int32_t c, uint64_t n)
{
	uint64_t		i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)src;
	if (n == 0)
		return ((void *)s);
	i = 0;
	while (i < n)
	{
		if (*(s + i) == c)
			return (s + i);
		++i;
	}
	return (0);
}
