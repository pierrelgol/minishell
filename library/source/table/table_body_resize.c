/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_body_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:27:00 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/05 10:47:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	table_body_resize(t_table *table, uint64_t new_capacity)
{
	t_entry		*entry_old;
	uint64_t	capacity_old;
	uint64_t	i;

	entry_old = table->body;
	capacity_old = table->capacity;
	table->body = table_body_create(table->allocator, new_capacity);
	table->capacity = new_capacity;
	i = 0;
	while (i < capacity_old)
	{
		if (entry_old[i].key != NULL)
			table_entry_set(table, entry_old[i].key, entry_old[i].value);
		++i;
	}
}
