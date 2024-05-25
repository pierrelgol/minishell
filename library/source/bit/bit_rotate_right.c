/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_rotate_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:16:13 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:34:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uint64_t	bit_rotate_right(uint64_t num, uint64_t shift)
{
	shift %= sizeof(num) << 3;
	return ((num >> shift) | (num << ((sizeof(num) << 3) - shift)));
}
