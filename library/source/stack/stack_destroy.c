/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:49:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:49:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_stack	*stack_destroy(t_stack *self)
{
	struct s_allocator	*allocator;

	allocator = self->allocator;
	list_destroy(self->top);
	list_destroy(self->freelist);
	allocator->destroy(allocator, self);
	return (0);
}
