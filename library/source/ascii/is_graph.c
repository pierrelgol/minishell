/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:54:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 12:54:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

inline bool	is_graph(const int32_t ch)
{
	return (!is_ctrl(ch) && !is_space(ch));
}