/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:57:09 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/22 08:01:54 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (!haystack && !len)
		return ((char *)needle);
	needle_len = ft_strlen((char *)needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i + needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*haystack;
	char	*needle;
	char	*test;
	char	*test1;

	if (argc != 3)
		return (1);
	haystack = argv[1];
	needle = argv[2];
	test = ft_strnstr(haystack, needle, 20);
	test1 = ft_strnstr(haystack, needle, 20);
    
	printf("original : %s", test1);
	printf("custom : %s", test);
	   return (0);
}*/
