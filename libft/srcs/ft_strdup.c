/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:44:09 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/22 08:34:48 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*copied;

	len = (size_t)ft_strlen((char *)s1);
	copied = (char *)malloc(sizeof(char) * (len + 1));
	if (!copied)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copied[i] = s1[i];
		i++;
	}
	copied[i] = '\0';
	return (copied);
}
