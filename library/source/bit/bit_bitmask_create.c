/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_bitmask_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:19:39 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:33:51 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	bit_bitmask_create(uint64_t start, uint64_t end)
{
	uint64_t	mask;

	if (start > end || start > 63 || end > 63)
		return (0);
	mask = ((1ull << (end - start + 1)) - 1) << start;
	return (mask);
}
