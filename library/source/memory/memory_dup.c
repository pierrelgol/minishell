/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:54:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/11 19:54:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*memory_dup(void *ptr, uint64_t size)
{
	void	*dup;

	dup = memory_alloc(size);
	memory_copy(dup, ptr, size);
	return (dup);
}
