/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_ccopy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:33:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:33:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

void	*memory_ccopy(void *const dest, const int32_t byte,
		const void *const source, const uint64_t dsize)
{
	const uint8_t	b = (const uint8_t)byte;
	uint8_t			i;

	const uint8_t *const sptr = (const uint8_t *const)source;
	uint8_t *const dptr = (uint8_t *const)dest;
	i = 0;
	while (i < dsize)
	{
		if (*(sptr + i) == b)
			return ((void *)(source + i + 1));
		*(dptr + i) = *(sptr + i);
		++i;
	}
	return (NULL);
}
