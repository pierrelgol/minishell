/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpa_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:31:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/16 09:20:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void *gpa_dup(t_allocator *self, void *ptr, uint64_t bytes)
{
	void *dup;

	dup = gpa_create(self, bytes);
	if (!dup)
		return (ptr);
	memory_copy(dup, ptr, bytes);
	return (dup);
}
