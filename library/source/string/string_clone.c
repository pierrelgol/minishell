/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:28:34 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:28:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

char	*string_clone(const char *const source)
{
	const uint64_t	slen = string_length(source);

	char *const result = memory_alloc(slen + 1);
	return (memory_copy(result, source, slen));
}
