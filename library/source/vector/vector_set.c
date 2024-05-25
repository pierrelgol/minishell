/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:21:01 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 19:21:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool vector_set_front(t_vector *vector, uintptr_t value)
{
	if (vector_is_empty(vector))
		return (false);
	*vector_get_front(vector) = value;
	return (true);
}

bool vector_set_back(t_vector *vector, uintptr_t value)
{
	if (vector_is_empty(vector))
		return (false);
	*vector_get_back(vector) = value;
	return (true);
}

bool vector_set_at(t_vector *vector, uintptr_t value, uint64_t index)
{
	if (vector_is_empty(vector))
		return (false);
	*vector_get_at(vector, index) = value;
	return (true);
}
