/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpa_dupz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:31:27 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/16 09:20:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void *gpa_dupz(t_allocator *self, void *ptr, uint64_t bytes)
{
	void *dup;

	dup = gpa_create(self, bytes + 1);
	if (!dup)
		return (ptr);
	memory_copy(dup, ptr, bytes);
	((char *) dup)[bytes] = 0x00;
	return (dup);
}
