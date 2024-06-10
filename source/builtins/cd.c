/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <plgol.perso@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:05:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/10 11:05:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_builtins *builtins_sync_cd(t_builtins *self)
{
	char	path_buffer[PATH_MAX];

	if (self->cd_cwd != )
	self->cd_cwd = string_clone(getcwd(path_buffer, PATH_MAX));
	return (self);
}
t_builtins *builtins_clear_cd(t_builtins *self);
t_builtins *builtins_destroy_cd(t_builtins *self);


