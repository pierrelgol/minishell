/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:32:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:32:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char *direct_io(t_shell *shell)
{
	static int i = 1;

	if (i < shell->argc)
		return (shell->argv[i++]);
	return (NULL);
}
