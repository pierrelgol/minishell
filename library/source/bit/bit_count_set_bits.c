/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_count_set_bits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:15:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:34:14 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	bit_count_set_bits(uint64_t num)
{
	uint32_t	count;

	count = 0;
	while (num)
	{
		num &= (num - 1);
		++count;
	}
	return (count);
}
