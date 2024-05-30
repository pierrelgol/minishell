/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:29:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 14:29:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool it_reset(t_iterator *self)
{
	if (vector_is_empty(self->vec))
		return (false);
	self->index = 0;
	return (true);
}
