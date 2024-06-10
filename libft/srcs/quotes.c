/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:41 by bifernan          #+#    #+#             */
/*   Updated: 2024/04/08 15:15:57 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ft_skip_quote(char const **str)
{
	int	is_quote;

	is_quote = 0;
	if (**str == '\'')
	{
		is_quote = 1;
		*str += 1;
	}
	while (**str != '\'' && **str != '\0' && is_quote)
		*str += 1;
	if (**str == '\'')
		*str += 1;
}

int	ft_quotelen(char const *str)
{
	int	count;

	count = 0;
	if (*str == '\'')
		str++;
	while (*str != '\'' && *str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

void	quote_handel(int *is_quote, int *is_word, int *word_count)
{
	*is_quote = !*is_quote;
	if (!*is_quote)
		*is_word = 0;
	else
	{
		*is_word = 1;
		*word_count += 1;
	}
}

int	ft_single_quote_count(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '\'')
			count++;
		str++;
	}
	return (count);
}
