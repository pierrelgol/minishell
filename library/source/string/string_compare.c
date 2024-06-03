/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:45:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 12:45:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

int64_t	string_compare(const char *const source1, const char *const source2)
{
	uint64_t	i;

	const uint8_t *const ps1 = (const uint8_t *const)source1;
	const uint8_t *const ps2 = (const uint8_t *const)source2;
	if (!source1 || !source2)
		return (0);
	i = 0;
	while (*(ps1 + i) && *(ps1 + i) == *(ps2 + i))
		i += 1;
	return (*(ps1 + i) - *(ps2 + i));
}

int64_t	string_ncompare(const char *const source1, const char *const source2,
		const uint64_t n)
{
	uint64_t	i;

	const uint8_t *const ps1 = (const uint8_t *const)source1;
	const uint8_t *const ps2 = (const uint8_t *const)source2;
	if (!source1 || !source2)
		return (0);
	i = 0;
	while (*(ps1 + i) && *(ps1 + i) == *(ps2 + i) && i < n)
		i += 1;
	return (*(ps1 + i) - *(ps2 + i));
}
