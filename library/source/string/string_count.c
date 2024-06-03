/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:40:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 11:40:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

uint64_t	string_count(const char *const source, const char *const delimiters)
{
	char		*set;
	uint64_t	result;
	uint64_t	i;

	set = (char[256]){0};
	if (!source || !delimiters)
		return (0);
	i = 0;
	while (*(delimiters + i))
	{
		set[(uint64_t) * (delimiters + i)] = 1;
		i += 1;
	}
	i = 0;
	result = 0;
	while (*(source + i))
	{
		if (set[(uint64_t) * (source + i)] == 1)
			result += 1;
		i += 1;
	}
	return (result);
}

uint64_t	string_wcount(const char *const source,
		const char *const delimiters)
{
	uint64_t	count;
	uint64_t	slen;
	uint64_t	i;

	if (!source || !delimiters)
		return (0);
	i = 0;
	slen = string_length(source);
	count = 0;
	while (i < slen)
	{
		i += string_span(source + i, delimiters);
		if (i < slen)
			count += 1;
		i += string_cspan(source + i, delimiters);
	}
	return (count);
}
