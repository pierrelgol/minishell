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

typedef struct s_hashmap_entry t_hashmap_entry;
typedef struct s_hashmap       t_hashmap;

struct s_hashmap_entry
{
	char *key;
	char *val;
};

t_hashmap_entry *hashmap_entry_create(const char *const key, const char *const value);
int64_t          hashmap_entry_compare(uintptr_t a, uintptr_t b);
t_hashmap_entry *hashmap_entry_destroy(t_hashmap_entry *self);

struct s_hashmap
{
	uint64_t  capacity;
	uint64_t  count;
	t_vector *bucket;
};

t_hashmap *hashmap_create(const uint64_t capacity);
char      *hashmap_get(t_hashmap *self, char *key);
char      *hashmap_del(t_hashmap *self, char *key);
bool 	  hashmap_put(t_hashmap *self, const char *const key, const char *const value);
bool	  hashmap_is_empty(t_hashmap *self);
t_hashmap *hashmap_destroy_entries(t_hashmap *self);
t_hashmap *hashmap_destroy(t_hashmap *self);

struct s_shell
{
	char  **envp;
	char  **argv;
	int64_t argc;
};

t_shell *shell_create(int32_t argc, char **argv, char **envp);
t_shell *shell_destroy(t_shell *self);

#endif
