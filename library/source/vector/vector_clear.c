/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:00:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 09:00:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"
#include <stdint.h>

void	vector_clear(t_vector *self)
{
	self->data = memory_set(self->data, 0x00, self->size * sizeof(uintptr_t));
	self->count = 0;
}
