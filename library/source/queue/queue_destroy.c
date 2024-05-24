/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:47:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 08:47:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_queue	*queue_destroy(t_queue *self)
{
	struct s_allocator	*allocator;

	allocator = self->allocator;
	list_destroy(self->head);
	list_destroy(self->freelist);
	allocator->destroy(allocator, self);
	return (0);
}
