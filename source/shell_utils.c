/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:00:03 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 16:00:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char **allocator_destroy_split(t_allocator *allocator, char **split)
{
	uint64_t	i;

	i = 0;
	while (split[i])
		allocator->destroy(allocator, split[i++]);
	allocator->destroy(allocator, split);
	return (NULL);
}
