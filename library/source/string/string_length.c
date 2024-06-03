/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:13:10 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 10:13:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

uint64_t	string_length(const char *const source)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (*(source + i))
		i += 1;
	return (i);
}
