/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:01:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:01:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

void	*memory_search(const void *const source, const int32_t byte,
		const uint64_t ssize)
{
	const uint8_t	b = (const uint8_t)byte;
	uint64_t		i;

	const uint8_t *const ptr = (const uint8_t *const)source;
	i = 0;
	while (i < ssize && *(ptr + i) != b)
		i += 1;
	if (i == ssize)
		return (NULL);
	return ((void *)ptr + i);
}
