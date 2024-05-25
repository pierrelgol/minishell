/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_even.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:26:09 by plgol.perso       #+#    #+#             */
/*   Updated: 2024/05/16 09:31:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool is_even(int32_t ch)
{
	return (!(ch & 1));
}
