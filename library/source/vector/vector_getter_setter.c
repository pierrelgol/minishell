/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:15:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 11:15:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

uintptr_t vector_get_at(t_vector *vector, const uint64_t index)
{
	if (vector_is_empty(vector) || index > vector->count)
		return (0);
	return (vector->data[index]);
}

void vector_set_at(t_vector *vector, uintptr_t elem, const uint64_t index)
{
	if (vector_is_empty(vector) || index > vector->count)
		return ;
	vector->data[index] = elem;
}
