/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:26:44 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 13:26:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_hashmap_entry	*hashmap_entry_create(const char *const key,
		const char *const value)
{
	t_hashmap_entry	*entry;

	entry = (t_hashmap_entry *)memory_alloc(sizeof(t_hashmap_entry));
	if (!entry)
		return (NULL);
	entry->key = string_clone(key);
	entry->val = string_clone(value);
	if (!entry->key || !entry->val)
	{
		if (entry->key)
			memory_dealloc(entry->key);
		if (entry->val)
			memory_dealloc(entry->val);
		memory_dealloc(entry);
		return (NULL);
	}
	return (entry);
}

int64_t	hashmap_entry_compare(uintptr_t a, uintptr_t b)
{
	t_hashmap_entry	*entry_a;
	t_hashmap_entry	*entry_b;

	entry_a = (t_hashmap_entry *)a;
	entry_b = (t_hashmap_entry *)b;
	return (string_compare(entry_a->key, entry_b->key));
}

t_hashmap_entry	*hashmap_entry_destroy(t_hashmap_entry *self)
{
	if (self)
	{
		if (self->key)
			memory_dealloc(self->key);
		if (self->val)
			memory_dealloc(self->val);
		memory_dealloc(self);
	}
	return (NULL);
}

t_hashmap	*hashmap_create(const uint64_t capacity)
{
	t_hashmap	*self;

	self = (t_hashmap *)memory_alloc(sizeof(t_hashmap));
	if (!self)
		return (NULL);
	self->bucket = vector_create_with_capacity(capacity);
	if (!self->bucket)
	{
		memory_dealloc(self);
		return (NULL);
	}
	self->capacity = capacity;
	self->count = 0;
	return (self);
}

char	*hashmap_get(t_hashmap *self, char *key)
{
	t_hashmap_entry	temp_entry;
	t_hashmap_entry	*entry;
	int64_t			index;

	if (!self || !key)
		return (NULL);
	temp_entry = (t_hashmap_entry){.key = key, .val = NULL};
	index = vector_search(self->bucket, (uintptr_t)&temp_entry,
			hashmap_entry_compare);
	if (index == -1)
		return (NULL);
	entry = (t_hashmap_entry *)vector_get_at(self->bucket, index);
	if (!entry)
		return (NULL);
	return (entry->val);
}
