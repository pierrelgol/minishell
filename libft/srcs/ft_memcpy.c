/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:38:38 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/06 12:44:57 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr_to_dest;
	char	*ptr_to_src;

	if (!dest && !src)
		return (0);
	ptr_to_dest = (char *)dest;
	ptr_to_src = (char *)src;
	while (n > 0)
	{
		*ptr_to_dest = *ptr_to_src;
		ptr_to_dest++;
		ptr_to_src++;
		n--;
	}
	return (dest);
}
