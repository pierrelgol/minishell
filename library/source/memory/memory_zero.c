/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:20:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:20:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header/slib.h"

void	*memory_zero(void *const dest, const uint64_t dsize)
{
	const uint8_t	b = 0x00;
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
