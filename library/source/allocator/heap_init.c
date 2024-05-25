/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:12:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 10:12:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_allocator	*heap_init(void)
{
	t_allocator	*heap;

	heap = memory_alloc(sizeof(t_allocator));
	heap->clear = heap_clear;
	heap->create = heap_create;
	heap->destroy = heap_destroy;
	heap->dup = heap_dup;
	heap->dupz = heap_dupz;
	heap->reserve = heap_reserve;
	return (heap);
}
