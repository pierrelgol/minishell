/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_nclone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:30:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 11:30:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

char	*string_nclone(const char *const source, const uint64_t n)
{
	char *const result = memory_alloc(n + 1);
	return (memory_copy(result, source, n));
}
