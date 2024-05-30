/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_mut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:32:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 14:32:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t it_insert_front(t_iterator *self, uintptr_t elem)
{
	vector_insert_after(self->vec, elem, self->index);
	return (elem);
}

uintptr_t it_remove_front(t_iterator *self)
{
	uintptr_t elem;

	elem = it_peeknext(self);
	vector_remove_after(self->vec, self->index);
	return (elem);
}
