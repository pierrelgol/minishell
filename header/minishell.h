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

#ifndef DIRECT_IO
#define DIRECT_IO 0
#endif

typedef struct s_prompt        t_prompt;
typedef struct s_input         t_input;
typedef struct s_environment   t_environment;
typedef struct s_lexer         t_lexer;
typedef struct s_shell         t_shell;
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

bool hashmap_is_empty(t_hashmap *self);
bool hashmap_put(t_hashmap *self, const char *const key, const char *const value);
char      *hashmap_del(t_hashmap *self, char *key);
char      *hashmap_get(t_hashmap *self, char *key);
t_hashmap *hashmap_create(const uint64_t capacity);
t_hashmap *hashmap_destroy(t_hashmap *self);
t_hashmap *hashmap_destroy_entries(t_hashmap *self);

struct s_shell
{
	bool           is_dirty;
	char         **argv;
	char         **envp;
	int64_t        argc;
	t_environment *env;
	t_input       *input;
	t_lexer       *lexer;
	t_prompt      *prompt;
};

t_shell *shell_create(int32_t argc, char **argv, char **envp);
bool	shell_run(t_shell *shell);
bool	shell_clear(t_shell *shell);
t_shell *shell_destroy(t_shell *self);

struct s_environment
{
	t_vector  *keys;
	t_hashmap *vars;
	bool       is_dirty;
};

t_environment *environment_create(char **envp);
t_environment *environment_build(t_environment *self, char **envp);
int64_t        enviroment_compare(uintptr_t a, uintptr_t b);
bool           enviroment_put(t_environment *self, char *variable, char *value);
char          *enviroment_get(t_environment *self, char *variable);
bool           enviroment_rem(t_environment *self, char *variable);
t_environment *environment_destroy(t_environment *self);

struct s_prompt
{
	t_environment *env;
	char          *prompt;
	bool           is_dirty;
};

t_prompt *prompt_create(t_environment *env);
char     *prompt_get(t_prompt *self);
t_prompt *prompt_clear(t_prompt *self);
t_prompt *prompt_destroy(t_prompt *self);

struct s_input
{
	bool           is_dirty;
	int64_t        index;
	char          *line;
	char         **argv;
	int64_t        argc;
	t_environment *env;
	t_prompt      *prompt;
};

t_input *input_create(t_environment *env, t_prompt *prompt, int64_t argc, char **argv);
t_input *input_clear(t_input *self);
char    *input_get(t_input *self);
t_input *input_destroy(t_input *self);

struct s_lexer
{
	char     *input;
	char     *delim;
	t_vector *output;
	bool      is_dirty;
};

t_lexer  *lexer_create();
t_lexer  *lexer_init(t_lexer *self, char *input, char *delim);
t_vector *lexer_lex(t_lexer *self);
t_lexer  *lexer_clear(t_lexer *self);
t_lexer  *lexer_destroy(t_lexer *self);

#endif
