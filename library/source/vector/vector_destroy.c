/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:14:01 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 10:14:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

t_vector	*vector_destroy(t_vector *self)
{
	if (self)
	{
		if (self->data)
			memory_dealloc(self->data);
		memory_dealloc(self);
	}
	return (NULL);
}
