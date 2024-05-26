/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:35:43 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 14:35:43 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

uintptr_t it_match(t_iterator *self, uintptr_t elem, bool(compare)(uintptr_t e1, uintptr_t e2))
{
	uintptr_t e;

	e = it_peeknext(self);
	return (compare(elem, e) == true);
}

uint64_t it_skip(t_iterator *self, uintptr_t elem, bool(compare)(uintptr_t e1, uintptr_t e2))
{
	uint64_t count;

	count = 0;
	while (it_match(self, elem, compare))
	{
		it_next(self);
		++count;
	}
	return (count);
}

bool it_contains_matching(t_iterator *self, uintptr_t elem, bool(compare)(uintptr_t e1, uintptr_t e2))
{
	it_save(self);
	while (!it_end(self))
	{
		if (it_match(self, elem, compare))
		{
			it_restore(self);
			return (true);
		}
		it_next(self);
	}
	it_restore(self);
	return (false);
}
