/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:15:27 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 10:15:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

bool	vector_is_empty(t_vector *self)
{
	return (self->count == 0);
}

bool	vector_is_full(t_vector *self)
{
	return (self->count == self->capacity);
}
