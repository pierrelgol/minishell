/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:08:53 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/22 08:09:24 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_strlet(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_manager(void)
{
	char	*result;

	result = (char *)malloc(sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	j = ft_strlet((char *)s1) - 1;
	k = 0;
	result = NULL;
	if (!set)
		return ((char *)s1);
	while (ft_is_set(s1[i], set) && s1[i])
		i++;
	if (i > j)
		return (ft_manager());
	while (ft_is_set(s1[j], set) && j >= 0)
		j--;
	result = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!result)
		return (NULL);
	while (i <= j)
		result[k++] = s1[i++];
	result[k] = '\0';
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char const *s1 = "x x x x x x x x o o o o o o o o o o x x";
	char const *s2 = "";
	char const *s3 = "il n'a pas de separateurs";
	char const *s4 = "il n'y a que des separateurs";
	char	*rez;
	
	rez = ft_strtrim(s1, "x ");
	printf(" resultat 1 : %s\n", rez);
	free(rez);
	
	rez = ft_strtrim(s2, "sep");
	printf(" resultat 2 : %s\n", rez);
	free(rez);
	
	rez = ft_strtrim(s3, "");
	printf(" resultat 3 : %s\n", rez);
	free(rez);
	
	rez = ft_strtrim(s4, "il n'y a que des separateurs");
	printf(" resultat 4 : %s\n", rez);
	free(rez);

	return (0);
}*/
