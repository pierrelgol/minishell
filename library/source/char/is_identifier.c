/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_identifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:18:12 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 14:18:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	is_identifier_start(int32_t ch)
{
	return (is_alpha(ch) || ch == '_');
}

bool	is_identifier(int32_t ch)
{
	return (is_alnum(ch) || ch == '_');
}

