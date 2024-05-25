/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:20:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 13:20:14 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_bitset	bitset_and(const t_bitset *bitset1, const t_bitset *bitset2)
{
	t_bitset	result;
	uint64_t	index;

	index = 0;
	while (index < 4)
	{
		result.set[index] = bitset1->set[index] & bitset2->set[index];
		++index;
	}
	return (result);
}

t_bitset	bitset_or(const t_bitset *bitset1, const t_bitset *bitset2)
{
	t_bitset	result;
	uint64_t	index;

	index = 0;
	while (index < 4)
	{
		result.set[index] = bitset1->set[index] | bitset2->set[index];
		++index;
	}
	return (result);
}

t_bitset	bitset_xor(const t_bitset *bitset1, const t_bitset *bitset2)
{
	t_bitset	result;
	uint64_t	index;

	index = 0;
	while (index < 4)
	{
		result.set[index] = bitset1->set[index] ^ (bitset2->set[index]);
		++index;
	}
	return (result);
}

t_bitset	bitset_difference(const t_bitset *bitset1, const t_bitset *bitset2)
{
	t_bitset	result;
	uint64_t	index;

	index = 0;
	while (index < 4)
	{
		result.set[index] = bitset1->set[index] & ~(bitset2->set[index]);
		++index;
	}
	return (result);
}
