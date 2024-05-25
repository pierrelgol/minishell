/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:14:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/07 12:14:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*memory_realloc(void *ptr, uint64_t osize, uint64_t nsize)
{
	void	*new_ptr;

	new_ptr = memory_zalloc(nsize);
	memory_copy(new_ptr, ptr, osize);
	memory_dealloc(ptr);
	return (new_ptr);
}
