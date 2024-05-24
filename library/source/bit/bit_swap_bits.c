/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_swap_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:17:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:35:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	bit_swap_bits(uint64_t num, uint64_t p1, uint64_t p2, uint64_t nb)
{
	uint64_t	swap;
	uint64_t	mask;

	mask = ((1ull << nb) - 1) << p1 | ((1ull << nb) - 1) << p2;
	swap = (num >> p1) ^ (num >> p2);
	swap &= ((1ull << nb) - 1);
	return (num ^ (((swap << p1) | (swap << p2)) & mask));
}
