/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:20:09 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 13:20:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_bitset	bitset_init_empty(void)
{
	t_bitset	bitset;

	memory_set(&bitset, sizeof(t_bitset), BITSET_SIZE);
	return (bitset);
}

t_bitset	bitset_init_from_str(const char *string)
{
	t_bitset	bitset;
	uint8_t		offset;
	uint8_t		index;
	uint64_t	*set;

	bitset = bitset_init_empty();
	while (*string)
	{
		index = (uint8_t)(*string);
		offset = index % 64;
		set = &bitset.set[index / 64];
		*set |= (1ULL << offset);
		string++;
	}
	return (bitset);
}

t_bitset	bitset_set_bit_range(t_bitset *bitset ,const char *string)
{
	uint8_t		offset;
	uint8_t		index;
	uint64_t	*set;

	while (*string)
	{
		index = (uint8_t)(*string);
		offset = index % 64;
		set = &bitset->set[index / 64];
		*set |= (1ULL << offset);
		string++;
	}
	return (*bitset);
}

t_bitset	bitset_reset(t_bitset *bitset)
{
	memory_set(bitset, sizeof(t_bitset), BITSET_SIZE);
	return (*bitset);
}

void	bitset_set_bit(t_bitset *bitset, const uint64_t index, const bool value)
{
	uint8_t		offset;
	uint64_t	*set;

	if (index < BITSET_SIZE)
	{
		set = (uint64_t *)&bitset->set[index / 64];
		offset = index % 64;
		if (value)
			*set |= (1ULL << offset);
		else
			*set &= ~(1ULL << offset);
	}
}

bool	bitset_is_set(const t_bitset *bitset, const uint64_t index)
{
	uint8_t		offset;
	uint64_t	set;

	if (index < BITSET_SIZE)
	{
		set = (uint64_t)bitset->set[index / 64];
		offset = index % 64;
		return ((set >> offset) & 1ULL);
	}
	return (false);
}
