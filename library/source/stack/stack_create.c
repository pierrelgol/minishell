/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:48:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:48:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_stack	*stack_create(struct s_allocator *allocator)
{
	t_stack	*stack;

	stack = allocator->create(allocator, sizeof(t_stack));
	stack->allocator = allocator;
	stack->count = 0;
	stack->size = 1;
	stack->top = 0;
	stack->freelist = list_create(allocator);
	return (stack);
}
