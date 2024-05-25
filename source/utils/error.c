/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:32:01 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:32:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void _minishell_expect(bool condition, char *function)
{
	if (!condition)
		print(2, "[WARN] | Assertion failed in : %s\n", function);
}

void _minishell_assert(bool condition, char *function)
{
	if (!condition)
	{
		print(2, "[ERR] | Assertion failed in : %s\n", function);		
		abort();
	}
}
