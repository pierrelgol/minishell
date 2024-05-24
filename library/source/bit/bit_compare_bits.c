/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_compare_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:47 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:34:01 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

int	bit_compare_bits(uint64_t num1, uint64_t num2, uint64_t bitPos1,
		uint64_t bitPos2)
{
	uint64_t	mask1;
	uint64_t	mask2;
	uint64_t	bit1;
	uint64_t	bit2;

	mask1 = 1 << bitPos1;
	mask2 = 1 << bitPos2;
	bit1 = (num1 & mask1) >> bitPos1;
	bit2 = (num2 & mask2) >> bitPos2;
	if (bit1 == bit2)
		return (0);
	else if (bit1 < bit2)
		return (-1);
	else
		return (1);
}
