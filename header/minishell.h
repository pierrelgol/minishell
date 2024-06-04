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
typedef struct s_token         t_token;
typedef struct s_tokenizer     t_tokenizer;
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
	t_tokenizer   *tokenizer;
	t_lexer       *lexer;
	t_prompt      *prompt;
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
	KIND_NO_KIND,
	KIND_ID,
	KIND_CMD,
	KIND_SPC,
	KIND_PATH,
	KIND_FILE,
	KIND_BLTN,
	KIND_ARG,
	KIND_VAR,
	KIND_ERR,
	KIND_PIPE,
	KIND_AMPERSAND,
	KIND_SCOLON,
	KIND_RRDIR,
	KIND_LRDIR,
	KIND_HERE_DOC,
	KIND_APPEND,

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
t_tokenizer *tokenizer_clear(t_tokenizer *self);
t_tokenizer *tokenizer_destroy(t_tokenizer *self);

struct s_lexer
{
	t_environment *env;
	t_tokenizer   *tokenizer;
	t_vector      *token_vector;
	bool	is_dirty;
};

t_lexer  *lexer_create(t_environment *env, t_tokenizer *tokenizer);
t_vector *lexer_lex(t_lexer *self, t_vector *input);

void	lexer_identify_all_whitespaces(t_lexer *self, t_vector *it);
void	lexer_identify_all_builtins(t_lexer *self, t_vector *it);
void	lexer_identify_all_variables(t_lexer *self, t_vector *it);
void	lexer_identify_all_commands(t_lexer *self, t_vector *it);
void	lexer_identify_all_terminals(t_lexer *self, t_vector *it);

void	lexer_identify_all_quotes(t_lexer *self, t_vector *it);
void	lexer_identify_all_assignments(t_lexer *self, t_vector *it);
void	lexer_identify_all_arguments(t_lexer *self, t_vector *it);
void	lexer_identify_all_path(t_lexer *self, t_vector *it);
void	lexer_identify_all_redirect(t_lexer *self, t_vector *it);

void	lexer_identify_all_boolean(t_lexer *self, t_vector *it);
void	lexer_identify_all_files(t_lexer *self, t_vector *it);
void	lexer_identify_all_keywords(t_lexer *self, t_vector *it);
void	lexer_identify_all_identifiers(t_lexer *self, t_vector *it);
void	lexer_identify_all_operators(t_lexer *self, t_vector *it);

void	lexer_identify_all_punctuators(t_lexer *self, t_vector *it);
void	lexer_identify_all_string_litterals(t_lexer *self, t_vector *it);
void	lexer_identify_all_expansions(t_lexer *self, t_vector *it);

t_lexer  *lexer_clear(t_lexer *self);
t_lexer  *lexer_destroy(t_lexer *self);

#endif
