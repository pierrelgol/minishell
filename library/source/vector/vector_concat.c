/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:40:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/24 19:40:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_vector *vector_concat(t_vector *dest, t_vector *src)
{
	uint64_t i;
	clib_assert(dest != NULL);
	clib_assert(src != NULL);
	i = 0;
	while (vector_end_of_vec(src, i))
		vector_insert_back(dest, vector_peek_at(src, i++));
	return (dest);
}
