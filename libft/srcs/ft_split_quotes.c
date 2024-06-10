/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:49:24 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/09 12:32:24 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

static int	ft_wordlen(char const *str, int (*f)(char))
{
	int	count;

	if (*str == '\'')
		return (ft_quotelen(str));
	count = 0;
	while (*str != '\0' && !f(*str))
	{
		count++;
		str++;
	}
	return (count);
}

static int	ft_word_count(char const *str, int (*f)(char))
{
	int	is_word;
	int	word_count;
	int	is_quote;

	is_word = 0;
	word_count = 0;
	is_quote = 0;
	while (*str != '\0')
	{
		if (*str == '\'')
			quote_handel(&is_quote, &is_word, &word_count);
		else if (!is_quote && !f(*str))
		{
			if (!is_word)
			{
				word_count++;
				is_word = 1;
			}
		}
		else
			is_word = 0;
		str++;
	}
	return (word_count);
}

static void	ft_strcpy(char const *src, char *dest, int (*f)(char))
{
	if (*src == '\'')
	{
		src++;
		while (*src != '\'' && *src != '\0')
			*dest++ = *src++;
	}
	else
	{
		while (*src != '\0' && !f(*src))
			*dest++ = *src++;
	}
	*dest = '\0';
}

char	**ft_split_quote(char const *s, int (*f)(char))
{
	int		i;
	char	**array;
	int		array_size;

	i = 0;
	array_size = ft_word_count(s, f) + 1;
	array = (char **)malloc(sizeof(char *) * array_size);
	if (!array)
		return (NULL);
	while (i < array_size - 1)
	{
		while (f(*s) && *s != '\0')
			s++;
		array[i] = (char *)malloc(sizeof(char) * (ft_wordlen(s, f) + 1));
		if (!array[i])
			ft_deallocate(array, i);
		ft_strcpy(s, array[i], f);
		if (*s == '\'')
			ft_skip_quote(&s);
		while (!f(*s) && *s != '\0')
			s++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
