/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_node_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:28:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 13:29:00 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_memory_node	*mem_node_next(t_memory_node *self)
{
	if (!self || !self->next)
		return (0);
	return (self->next);
}
