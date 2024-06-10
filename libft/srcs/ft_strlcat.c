/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:01:44 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/22 08:36:18 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	original_dst_len;

	i = 0;
	j = 0;
	if (!destsize && !dst)
		return (ft_strlen(src));
	original_dst_len = (size_t)ft_strlen(dst);
	if (destsize <= original_dst_len)
		return (destsize + ft_strlen((char *)src));
	while (dst[i] != '\0')
		i++;
	while (i < destsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (original_dst_len + ft_strlen((char *)src));
}
