/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:59:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:59:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t	vector_peek_at(t_vector *self, uint64_t index)
{
	if (index >= self->count)
		return (0);
	return (self->data[index]);
}
