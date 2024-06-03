/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:02:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 14:02:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_hashmap *hashmap_create(const uint64_t capacity)
{
	t_hashmap *self;

	self = (t_hashmap *) memory_alloc(sizeof(t_hashmap));
	if (!self)
		return (NULL);
	self->capacity = hashmap_find_capacity(capacity);
	self->count = 0;
	self->k_bucket = vector_create();
	if (!self->k_bucket)
		return (hashmap_destroy(self));
	self->v_bucket = vector_create();
	if (!self->v_bucket)
		return (hashmap_destroy(self));
	if (!vector_resize(self->k_bucket, self->capacity))
		return (hashmap_destroy(self));
	if (!vector_resize(self->v_bucket, self->capacity))
		return (hashmap_destroy(self));
	return (self);
}

uint64_t hashmap_find_capacity(const uint64_t capacity)
{
	static const uint64_t prime_numbers_look_up[26] = {
	    53,        97,         193,      389,       769,       1543,
	    3079,      6151,       12289,    24593,     49157,     98317,
	    196613,    393241,     786433,   1572869,   3145739,   6291469,
	    12582917,  25165843,   50331653, 100663319, 201326611, 402653189,
	    805306457, 1610612741,
	};
	uint64_t i;

	i = 0;
	while (i < sizeof(prime_numbers_look_up) / sizeof(prime_numbers_look_up[0]))
	{
		if (prime_numbers_look_up[i] > capacity)
			return (prime_numbers_look_up[i]);
		i += 1;
	}
	return (0);
}

t_hashmap *hashmap_destroy(t_hashmap *self)
{
	if (self)
	{
		if (self->k_bucket)
			self->k_bucket = vector_destroy(self->k_bucket);
		if (self->v_bucket)
			self->v_bucket = vector_destroy(self->v_bucket);
		memory_dealloc(self);
	}
	return (NULL);
}

uint64_t	hashmap_hash(char *str)
{
	unsigned long	seed;
	int				val;

	seed = 5381;
	while (*str)
	{
		val = *str++;
		seed = ((seed << 5) + seed) + (unsigned long)val;
	}
	return (seed);
}
