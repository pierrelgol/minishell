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

#include "common.h"
#include "minishell_2.h"
#include "slib.h"
#include <limits.h>
#include <readline/history.h>
#include <readline/readline.h>

#ifndef DIRECT_IO
#define DIRECT_IO 0
#endif

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
	t_linker      *linker;
	t_prompt      *prompt;
	t_tokenizer   *tokenizer;
	t_minishell   *minishell;
	t_builtins    *builtins;
};

t_shell *shell_create(int32_t argc, char **argv, char **envp);
bool     shell_run(t_shell *shell);
bool     shell_clear(t_shell *shell);
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

struct s_linker
{
	t_environment *env;
	char         **paths;
	char          *input;
	char          *output;
	bool           is_dirty;
};

t_linker *linker_create(t_environment *env);
t_linker *linker_init(t_linker *self, char *additional_dir);
bool      linker_resolve_exe(t_linker *self, char *exe);
bool      linker_resolve_path(t_linker *self, char *path);
char     *linker_resolve(t_linker *self, char *maybe_path, char flag);
t_linker *linker_clear(t_linker *self);
char     *linker_make_path(t_linker *self, char *root, char *maybe_path);
t_linker *linker_destroy(t_linker *self);

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

typedef enum e_token_kind
{
	KIND_AMPERSAND,
	KIND_AND,
	KIND_APPEND,
	KIND_ARG,
	KIND_ASSIGNMENT,
	KIND_BLTN,
	KIND_CMD,
	KIND_DQUOTE,
	KIND_ERR,
	KIND_FILE,
	KIND_HERE_DOC,
	KIND_ID,
	KIND_LRDIR,
	KIND_NO_KIND,
	KIND_OR,
	KIND_PATH,
	KIND_PIPE,
	KIND_QUOTE,
	KIND_RRDIR,
	KIND_SCOLON,
	KIND_SPC,
	KIND_VAR,
} t_token_kind;

struct s_token
{
	t_token_kind kind;
	uint64_t     len;
	uintptr_t    extra;
	char        *ptr;
};

t_token     *token_create(char *ptr);
void         token_print(t_token *token);
char        *token_get_str(t_token *self);
t_token_kind token_get_kind(t_token *self);
uintptr_t    token_get_extra(t_token *self);
void         token_set_str(t_token *self, char *str);
void         token_set_kind(t_token *self, t_token_kind kind);
void         token_set_extra(t_token *self, uintptr_t extra);
t_token     *token_destroy(t_token *self);

struct s_tokenizer
{
	t_vector *output;
	char     *input;
	char     *delim;
	bool      is_dirty;
};

t_tokenizer *tokenizer_create();
t_vector    *tokenizer_tokenize(t_tokenizer *self, char *input, char *delim);
t_vector    *tokenizer_get(t_tokenizer *self);
t_tokenizer *tokenizer_clear(t_tokenizer *self);
t_tokenizer *tokenizer_destroy(t_tokenizer *self);

struct s_lexer
{
	t_environment *env;
	t_tokenizer   *tokenizer;
	t_linker      *linker;
	t_vector      *token_vector;
	bool           is_dirty;
};

t_lexer *lexer_create(t_environment *env, t_tokenizer *tokenizer, t_linker *linker);
t_vector *lexer_get(t_lexer *self);
t_vector *lexer_lex(t_lexer *self, t_vector *input);

void lexer_identify_all_whitespaces(t_lexer *self, t_vector *it);
void lexer_identify_all_quotes(t_lexer *self, t_vector *it);
void lexer_identify_all_redirect(t_lexer *self, t_vector *it);
void lexer_identify_all_boolean(t_lexer *self, t_vector *it);
void lexer_identify_all_terminals(t_lexer *self, t_vector *it);

void lexer_identify_all_variables(t_lexer *self, t_vector *it);
void lexer_identify_all_identifiers(t_lexer *self, t_vector *it);
void lexer_identify_all_keywords(t_lexer *self, t_vector *it);
void lexer_identify_all_assignments(t_lexer *self, t_vector *it);
void lexer_identify_all_files(t_lexer *self, t_vector *it);

void lexer_identify_all_paths(t_lexer *self, t_vector *it);
void lexer_identify_all_commands(t_lexer *self, t_vector *it);
void lexer_identify_all_builtins(t_lexer *self, t_vector *it);
void lexer_identify_all_arguments(t_lexer *self, t_vector *it);
void lexer_identify_all_operators(t_lexer *self, t_vector *it);

t_lexer *lexer_clear(t_lexer *self);
t_lexer *lexer_destroy(t_lexer *self);

struct s_builtins
{
	t_environment     *env;
	t_builtins_cd     *blt_cd;
	t_builtins_echo   *blt_echo;
	t_builtins_env    *blt_env;
	t_builtins_export *blt_export;
	t_builtins_unset  *blt_unset;
	t_builtins_pwd    *blt_pwd;
};

t_builtins *builtins_create(t_environment *env);
t_builtins *builtins_destroy(t_builtins *self);

struct s_builtins_cd
{
	t_environment *env;
	char          *pwd;
	char          *opwd;
	char          *cwd;
};

t_builtins_cd *cd_create(t_environment *env);
bool           cd_change_directory(t_builtins_cd *self, char *target);
t_builtins_cd *cd_destroy(t_builtins_cd *self);

struct s_builtins_env
{
	t_environment *env;
	t_vector      *var;
};

t_builtins_env *env_create(t_environment *env);
bool            env_put(t_builtins_env *self, char *variable, char *value);
bool            env_print_one(t_builtins_env *self, char *variable);
bool            env_print_all(t_builtins_env *self);
t_builtins_env *env_destroy(t_builtins_env *self);

struct s_builtins_echo
{
	t_environment *env;
	int32_t        fd;
};

t_builtins_echo *echo_create(t_environment *env);
bool             echo_print(t_builtins_echo *self, char *message, bool flag);
t_builtins_echo *echo_destroy(t_builtins_echo *self);

struct s_builtins_export
{
	t_environment *env;
};

t_builtins_export *export_create(t_environment *env);
bool               export_export(t_builtins_export *self, char *k, char *v);
t_builtins_export *export_destroy(t_builtins_export *self);

struct s_builtins_unset
{
	t_environment *env;
};

t_builtins_unset *unset_create(t_environment *env);
bool              unset_unset(t_builtins_unset *self, char *variable);
t_builtins_unset *unset_destroy(t_builtins_unset *self);

struct s_builtins_pwd
{
	t_environment *env;
	char          *pwd;
};

t_builtins_pwd *pwd_create(t_environment *env);
bool            pwd_print(t_builtins_pwd *self);
t_builtins_pwd *pwd_destroy(t_builtins_pwd *self);

void dbg_shell_print(t_shell *shell);
void dbg_environment_print(t_environment *env);
void dbg_prompt_print(t_prompt *prompt);
void dbg_input_print(t_input *input);
void dbg_tokenizer_print(t_tokenizer *tokenizer);
void dbg_token_print(t_token *token);
void dbg_lexer_print(t_lexer *lexer);
void dbg_shell_print_verbose(t_shell *shell);
void dbg_environment_print_verbose(t_environment *env);
void dbg_prompt_print_verbose(t_prompt *prompt);
void dbg_input_print_verbose(t_input *input);
void dbg_tokenizer_print_verbose(t_tokenizer *tokenizer);
void dbg_token_print_verbose(t_token *token);
void dbg_lexer_print_verbose(t_lexer *lexer);

char **simple_split(const char *const source, const int32_t ch);

// SCOTCH

void from_token_vector_to_token_list(t_shell *shell, t_minishell *minishell, t_vector *token_vector);

#endif
