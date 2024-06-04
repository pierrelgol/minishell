/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:27:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 13:27:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char *hashmap_del(t_hashmap *self, char *key)
{
	t_hashmap_entry  temp_entry;
	t_hashmap_entry *entry;
	char            *value;
	int64_t          index;

	if (!self || !key)
		return (NULL);
	temp_entry = (t_hashmap_entry){.key = key, .val = NULL};
	index = vector_search(self->bucket, (uintptr_t) &temp_entry, hashmap_entry_compare);
	if (index == -1)
		return (NULL);
	entry = (t_hashmap_entry *) vector_remove_at(self->bucket, index);
	if (!entry)
		return (NULL);
	value = string_clone(entry->val);
	hashmap_entry_destroy(entry);
	self->count--;
	return value;
}

bool hashmap_put(t_hashmap *self, const char *const key, const char *const value)
{
	t_hashmap_entry *new_entry;
	char            *existing_value;
	bool             result;

	if (!self || !key || !value)
		return (false);
	existing_value = hashmap_get(self, (char *) key);
	if (existing_value)
		hashmap_del(self, (char *) key);
	new_entry = hashmap_entry_create(key, value);
	if (!new_entry)
		return (false);

	result = vector_insert_sorted(self->bucket, (uintptr_t) new_entry, hashmap_entry_compare);
	if (result)
		self->count++;
	else
		hashmap_entry_destroy(new_entry);
	return (result);
}

bool hashmap_is_empty(t_hashmap *self)
{
	return (self && self->count == 0);
}

t_hashmap *hashmap_destroy_entries(t_hashmap *self)
{
	t_hashmap_entry *entry;
	uint64_t         i;

	if (!self)
		return (NULL);
	i = 0;
	while (i < self->bucket->count)
	{
		entry = (t_hashmap_entry *) vector_get_at(self->bucket, i);
		hashmap_entry_destroy(entry);
		i += 1;
	}
	vector_clear(self->bucket);
	return (self);
}

t_hashmap *hashmap_destroy(t_hashmap *self)
{
	if (!self)
		return (NULL);
	hashmap_destroy_entries(self);
	vector_destroy(self->bucket);
	memory_dealloc(self);
	return (NULL);
}
