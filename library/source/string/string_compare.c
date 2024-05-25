/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:51:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 14:51:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

int32_t	string_compare(const char *s1, const char *s2)
{
	uint8_t	*ptr_s1;
	uint8_t	*ptr_s2;

	if (!s1 || !s2)
		return (0);
	ptr_s1 = (uint8_t *)s1;
	ptr_s2 = (uint8_t *)s2;
	while (*ptr_s1 && *ptr_s1 == *ptr_s2)
	{
		++ptr_s1;
		++ptr_s2;
	}
	return (*ptr_s1 - *ptr_s2);
}

int32_t	string_ncompare(const char *s1, const char *s2, const uint64_t n)
{
	uint8_t		*ptr_s1;
	uint8_t		*ptr_s2;
	uint64_t	i;

	if (!s1 || !s2 || !n)
		return (0);
	ptr_s1 = (uint8_t *)s1;
	ptr_s2 = (uint8_t *)s2;
	i = 0;
	while (*ptr_s1 && *ptr_s1 == *ptr_s2 && i < n)
	{
		++ptr_s1;
		++ptr_s2;
		++i;
	}
	return (*ptr_s1 - *ptr_s2);
}

int32_t	string_casecompare(const char *s1, const char *s2)
{
	uint8_t	*ptr_s1;
	uint8_t	*ptr_s2;

	if (!s1 || !s2)
		return (0);
	ptr_s1 = (uint8_t *)s1;
	ptr_s2 = (uint8_t *)s2;
	while (*ptr_s1 && (*ptr_s1 | 32) == (*ptr_s2 | 32))
	{
		++ptr_s1;
		++ptr_s2;
	}
	return ((*ptr_s1 | 32) - (*ptr_s2 | 32));
}

int32_t	string_ncasecompare(const char *s1, const char *s2, const uint64_t n)
{
	uint8_t		*ptr_s1;
	uint8_t		*ptr_s2;
	uint64_t	i;

	if (!s1 || !s2)
		return (0);
	ptr_s1 = (uint8_t *)s1;
	ptr_s2 = (uint8_t *)s2;
	i = 0;
	while (*ptr_s1 && (*ptr_s1 | 32) == (*ptr_s2 | 32) && i < n)
	{
		++ptr_s1;
		++ptr_s2;
		++i;
	}
	return ((*ptr_s1 | 32) - (*ptr_s2 | 32));
}
