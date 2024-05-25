/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:33:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/03 11:33:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

// void	*memory_move(void *dst, const void *src, uint64_t len)
// {
// 	const char	*ptr_src;
// 	char		*ptr_dst;

// 	ptr_src = (const char *)src;
// 	ptr_dst = (char *)dst;
// 	if (!dst && !src)
// 		return (NULL);
// 	if (dst > src)
// 	{
// 		while (len)
// 		{
// 			*(ptr_dst + len - 1) = *(ptr_src + len - 1);
// 			len--;
// 		}
// 		return (dst);
// 	}
// 	while (len--)
// 		*ptr_dst++ = *ptr_src++;
// 	return (dst);
// }


void	*memory_move(void *const dst, const void *const src, const uint64_t len)
{
	uint64_t i;

	i = len;
	if (dst > src)
	{
		while (i)
		{
			*((char * const)dst + i - 1) = *((const char *const)src + i - 1);
			i--;
		}
		return (dst);
	}
	while (i < len)
	{
		*((char * const)dst + i) = *((const char *const)src + i);
		--i;
	}
	return (dst);
}
