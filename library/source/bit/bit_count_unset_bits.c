/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_count_unset_bits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:15:52 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:34:21 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	bit_count_unset_bits(uint64_t num)
{
	uint64_t	count;

	count = 0;
	while (num)
	{
		num &= (num - 1);
		++count;
	}
	return ((sizeof(uint64_t) << 3) - count);
}
