/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_zalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:56:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/03 10:56:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"
#include <stdlib.h>

void	*memory_zalloc(uint64_t size)
{
	void	*ptr;

	ptr = malloc(size);
	return (memory_set(ptr, 0x00, size));
}
