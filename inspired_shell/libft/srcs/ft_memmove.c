/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:47:28 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/22 17:16:48 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (0);
	dest = (char *)dst;
	source = (char *)src;
	if (dest <= source)
	{
		while (len-- > 0)
			*dest++ = *source++;
		return (dst);
	}
	else
	{
		dest += len - 1;
		source += len - 1;
		while (len > 0)
		{
			*dest-- = *source--;
			len--;
		}
		return (dst);
	}
}
