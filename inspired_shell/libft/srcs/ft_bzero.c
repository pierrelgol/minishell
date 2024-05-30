/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:21:23 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/06 12:46:28 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*ptr_to_memory;

	ptr_to_memory = (char *)s;
	while (n > 0)
	{
		*ptr_to_memory = 0;
		ptr_to_memory++;
		n--;
	}
	return (s);
}
