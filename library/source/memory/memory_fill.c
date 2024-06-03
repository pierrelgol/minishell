/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:16:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:16:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

void	*memory_fill(void *const dest, const int32_t byte, const uint64_t dsize)
{
	const uint8_t	b = (const uint8_t)byte;
	uint64_t		i;

	uint8_t *const dptr = (uint8_t *const)dest;
	i = dsize;
	while (i != 0)
	{
		*(dptr + i - 1) = b;
		i -= 1;
	}
	return (dest);
}
