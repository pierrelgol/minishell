/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:14:58 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/09 12:19:10 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr_to_memory;

	ptr_to_memory = (char *)s;
	while (n > 0)
	{
		*ptr_to_memory = c;
		ptr_to_memory++;
		n--;
	}
	return (s);
}
