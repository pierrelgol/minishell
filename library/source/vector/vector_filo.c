/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_filo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:38:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 10:38:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

bool	vector_enqueue(t_vector *self, uintptr_t elem)
{
	return (vector_insert_at(self, elem, self->count));
}

uintptr_t	vector_dequeue(t_vector *self)
{
	if (vector_is_empty(self))
		return (0);
	return (vector_remove_at(self, 0));
}
