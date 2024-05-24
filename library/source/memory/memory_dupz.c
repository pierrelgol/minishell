/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dupz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:55:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/11 19:55:48 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*memory_dupz(void *ptr, uint64_t size)
{
	void	*dup;

	dup = memory_alloc(size + 1);
	memory_copy(dup, ptr, size);
	*((unsigned char *)dup + size) = 0x00;
	return (dup);
}
