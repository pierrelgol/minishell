/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clib_assert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:00:08 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 19:00:09 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	_clib_assert(bool condition, char *func)
{
	if (!condition)
	{
		print(2,"Failed assertion in %s! Aborting now...", func);
		abort();
	}
}
