/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:21 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/03 13:23:22 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "slib.h"
#include <readline/history.h>
#include <readline/readline.h>

typedef struct s_shell t_shell;

typedef struct s_hashmap t_hashmap;

struct s_hashmap
{
	uint64_t  capacity;
	uint64_t  count;
	t_vector *k_bucket;
	t_vector *v_bucket;
};

t_hashmap *hashmap_create(const uint64_t capacity);
uint64_t   hashmap_find_capacity(const uint64_t capacity);
t_hashmap *hashmap_destroy(t_hashmap *self);
uint64_t   hashmap_hash(char *str);

struct s_shell
{
	char  **envp;
	char  **argv;
	int64_t argc;
};

t_shell *shell_create(int32_t argc, char **argv, char **envp);
t_shell *shell_destroy(t_shell *self);

#endif
