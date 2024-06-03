/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_span.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:34:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 10:34:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

uint64_t	string_span(const char *const source, const char *const delimiters)
{
	uint64_t	result;
	uint64_t	i;

	char *const set = (char[256]){0};
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
	while (*(source + i) && set[(uint64_t) * (source + i)] == 1)
	{
		result += 1;
		i += 1;
	}
	return (result);
}
