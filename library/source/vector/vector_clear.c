/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:09:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 11:09:24 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

void	vector_clear(t_vector *self)
{
	memory_fill(self->data, 0x00, self->count * sizeof(uintptr_t));
	self->count = 0;
	self->index = 0;
	self->saved = 0;
}
