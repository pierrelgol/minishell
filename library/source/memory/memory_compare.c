/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:00:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 13:00:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

int64_t	memory_compare(const void *const s1, const void *const s2,
		const uint64_t n)
{
	uint64_t	i;

	const uint8_t *const s1ptr = (const uint8_t *const)s1;
	const uint8_t *const s2ptr = (const uint8_t *const)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n && *(s1ptr + i) == *(s2ptr + i))
		i += 1;
	return (*(s1ptr + i) - *(s2ptr + i));
}
