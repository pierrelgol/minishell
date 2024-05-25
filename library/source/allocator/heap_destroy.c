/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:52:51 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/15 11:52:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	*heap_destroy(t_allocator *self, void *ptr)
{
	if (self->logging)
	{
		printf("heap_destroy(self, %p)\n", ptr);
		self->dealloced += 1;
	}
	free(ptr);
	return (0);
}
