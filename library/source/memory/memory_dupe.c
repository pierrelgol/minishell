/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dupe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:47:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:47:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

void	*memory_dupe(const void *const source, const uint64_t ssize)
{
	void *const result = memory_alloc(ssize);
	return (memory_copy(result, source, ssize));
}
