/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dupz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:48:49 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:48:49 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

void	*memory_dupz(const void *const source)
{
	const uint64_t	slen = memory_search(source, 0x00, 2147483647) - source;

	if (slen == 0)
		return (memory_alloc(1));
	return (memory_dupe(source, slen));
}
