/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:56:31 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/09 15:06:07 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_strlex(char const *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*string;
	int		i;

	size = ft_strlex(s1) + ft_strlex(s2) + 1;
	string = (char *)malloc(sizeof(char) * size);
	i = 0;
	if (!string)
		return (NULL);
	while (*s1 != '\0')
	{
		string[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		string[i] = *s2;
		i++;
		s2++;
	}
	string[i] = '\0';
	return (string);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	char *s1;
	char *s2;
	char *s3;
	int	a;

	a = argc;
	s1 = argv[1];
	s2 = argv[2];
	s3 = ft_strjoin(s1, s2);
	printf("%s\n", s1);
	printf("       +\n");
	printf("%s\n", s2);
	printf("       =\n");
	printf("%s\n", s3);
	return (0);
}*/
