/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:59:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:59:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_vector	*vector_destroy(t_vector *self)
{
	struct s_allocator	*allocator;

	allocator = self->allocator;
	allocator->destroy(allocator, self->data);
	allocator->destroy(allocator, self);
	return (0);
}
