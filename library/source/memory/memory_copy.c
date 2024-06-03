/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:08:39 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 09:08:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

void	*memory_copy(void *const dest, const void *const source,
		const uint64_t bytes)
{
	uint64_t	i;

	const uint8_t *const sptr = (const uint8_t *const)source;
	uint8_t *const dptr = (uint8_t *const)dest;
	if (!dest && !source)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		*(dptr + i) = *(sptr + i);
		i += 1;
	}
	return (dest);
}
