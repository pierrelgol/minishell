/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:02:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 09:02:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

void	*memory_move(void *const dest, const void *const source,
		const uint64_t bytes)
{
	uint64_t	i;

	const uint8_t *const sptr = (const uint8_t *const)source;
	uint8_t *const dptr = (uint8_t *const)dest;
	if (!dest && !source)
		return (NULL);
	i = bytes;
	if (dest > source)
	{
		while (i != 0)
		{
			*(dptr + i - 1) = *(sptr + i - 1);
			i -= 1;
		}
		return (dest);
	}
	while (i != 0)
	{
		*(dptr + (bytes - i)) = *(sptr + (bytes - i));
		i -= 1;
	}
	return (dest);
}
