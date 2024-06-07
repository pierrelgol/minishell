/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:20:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 10:20:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

char	*string_search(const char *const haystack, const char *const needle,
		const uint64_t len)
{
	uint64_t	i;
	uint64_t	j;

	if (!haystack && len == 0)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i))
	{
		j = 0;
		while (*(haystack + i) && *(haystack + i) == *(needle + j) && i < len)
		{
			j += 1;
			i += 1;
		}
		if (!*(needle + j))
			return ((char *)&haystack[(int64_t)i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
