/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:52:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/18 11:52:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "clib.h"
#include <readline/history.h>
#include <readline/readline.h>

#define DEBUG_LINE "echo \"Hello World\";"
extern int64_t g_signal;

typedef struct s_token_payload   t_token_payload;
typedef struct s_token_buffer    t_token_buffer;
typedef struct s_token           t_token;
typedef struct s_shell           t_shell;
typedef struct s_shell_tokenizer t_shell_tokenizer;
typedef struct s_shell_lexer     t_shell_lexer;
typedef struct s_shell_linker    t_shell_linker;
typedef struct s_shell_env       t_shell_env;
typedef struct s_shell_input     t_shell_input;
typedef struct s_shell_prompt    t_shell_prompt;
typedef struct s_builtin_cd      t_builtin_cd;
typedef struct s_builtin_echo    t_builtin_echo;
typedef struct s_builtin_env     t_builtin_env;
typedef struct s_builtin_export  t_builtin_export;
typedef struct s_builtin_unset   t_builtin_unset;
typedef struct s_builtin_pwd     t_builtin_pwd;
typedef struct s_builtin_exit    t_builtin_exit;

int64_t signal_get(void);
void    signal_set(int64_t signal);

#define SH_SIG_DONE 0
#define SH_SIG_WORK 1
#define SH_SIG_ERRO 2

#ifndef DEBUG
#define DEBUG 1
#endif

#if DEBUG == 1
#undef assert
#define assert(b)                                                     \
	do                                                            \
	{                                                             \
		_minishell_expect((b), (char *) __PRETTY_FUNCTION__); \
	} while (0)
#elif DEBUG == 2
#define assert(b)                                                     \
	do                                                            \
	{                                                             \
		_minishell_assert((b), (char *) __PRETTY_FUNCTION__); \
	} while (0)
#else
#define assert(b) ((void) (b))
#endif

typedef enum e_token_kind
{
	KIND_NO_KIND,
} t_token_kind;

struct s_token_payload
{
	t_allocator *allocator;
};

t_token_payload *token_payload_create(t_allocator *allocator);
void token_payload_init(t_allocator *allocator, t_token_payload *self);
void token_payload_deinit(t_allocator *allocator, t_token_payload *self);
t_token_payload *token_payload_destroy(t_allocator *allocator, t_token_payload *self);

struct s_token_buffer
{
	t_allocator *allocator;
	t_vector    *tokens;
	uint64_t     index;
	uint64_t     count;
};

t_token_buffer *token_buffer_create(t_allocator *allocator);
void token_buffer_init(t_allocator *allocator, t_token_buffer *self, char **tokenized);

t_token *token_buffer_get_at(t_token_buffer *self, uint64_t index);
t_token *token_buffer_remove_at(t_token_buffer *self, uint64_t index);
void     token_buffer_push(t_token_buffer *self, t_token *token);
t_token *token_buffer_pop(t_token_buffer *self);
bool token_buffer_insert_at(t_token_buffer *self, t_token *token, uint64_t index);
bool     token_buffer_is_empty(t_token_buffer *self);
uint64_t token_buffer_kill(t_token_buffer *self, uint64_t n);
uint64_t token_buffer_eats(t_token_buffer *self, uint64_t n);
uint64_t token_buffer_skip_kind(t_token_buffer *self, t_token_kind kind);
uint64_t token_buffer_skip_string(t_token_buffer *self, char *str);
t_token *token_buffer_match_kind(t_token_buffer *self, t_token_kind kind, uint64_t n);
t_token *token_buffer_match_string(t_token_buffer *self, char *str, uint64_t n);
t_token *token_buffer_peek_curr(t_token_buffer *self);
t_token *token_buffer_peek_next(t_token_buffer *self);
t_token *token_buffer_peek_prev(t_token_buffer *self);
uint64_t token_buffer_get_curr_index(t_token_buffer *buffer);
bool     token_buffer_end_of_buffer(t_token_buffer *self, uint64_t i);

void buffer_print(t_token_buffer *self);
void token_buffer_deinit(t_allocator *allocator, t_token_buffer *self);
t_token_buffer *token_buffer_destroy(t_allocator *allocator, t_token_buffer *self);

struct s_token
{
	t_token_kind kind;
	uintptr_t    extra;
	char        *str;
	uint64_t     len;
};

t_token *token_create(t_allocator *allocator);
void     token_init(t_allocator *allocator, t_token *self, char *str);
void     token_deinit(t_allocator *allocator, t_token *self);
void     token_print(t_token *self);
t_token *token_destroy(t_allocator *allocator, t_token *self);

struct s_shell
{
	t_allocator       *allocator;
	int32_t            argc;
	char             **argv;
	char             **envp;
	t_builtin_cd      *blt_cd;
	t_builtin_echo    *blt_echo;
	t_builtin_env     *blt_env;
	t_builtin_export  *blt_export;
	t_builtin_unset   *blt_unset;
	t_builtin_pwd     *blt_pwd;
	t_builtin_exit    *blt_exit;
	t_shell_env       *sh_env;
	t_shell_prompt    *sh_prompt;
	t_shell_input     *sh_input;
	t_shell_tokenizer *sh_tokenizer;
	t_shell_lexer     *sh_lexer;
	t_shell_linker    *sh_linker;
};

t_shell *shell_create(t_allocator *allocator, int32_t argc, char **argv, char **envp);
void     shell_init(t_allocator *allocator, t_shell *self);
void     shell_main(t_allocator *allocator, t_shell *self);
void     shell_deinit(t_allocator *allocator, t_shell *self);
t_shell *shell_destroy(t_allocator *allocator, t_shell *self);

struct s_shell_tokenizer
{
	t_allocator *allocator;
	char        *input;
	char       **tokenized;
	t_bitset     delimiters;
};

t_shell_tokenizer *shell_tokenizer_create(t_allocator *allocator);
void shell_tokenizer_init(t_allocator *allocator, t_shell_tokenizer *self, char *line, char *delimiters);
char **shell_tokenizer_get(t_shell_tokenizer *self);
void   shell_tokenizer_deinit(t_allocator *allocator, t_shell_tokenizer *self);
t_shell_tokenizer *shell_tokenizer_destroy(t_allocator *allocator, t_shell_tokenizer *self);

struct s_shell_lexer
{
	t_allocator    *allocator;
	char          **tokenized;
	t_token_buffer *buffer;
};

t_shell_lexer *shell_lexer_create(t_allocator *allocator);
void shell_lexer_init(t_allocator *allocator, t_shell_lexer *self, char **tokenized);
t_token_buffer *shell_lexer_get(t_shell_lexer *self);
void            shell_lexer_deinit(t_allocator *allocator, t_shell_lexer *self);
t_shell_lexer *shell_lexer_destroy(t_allocator *allocator, t_shell_lexer *self);

struct s_shell_linker
{
	t_allocator *allocator;
};

t_shell_linker *shell_linker_create(t_allocator *allocator);
void            shell_linker_init(t_allocator *allocator, t_shell_linker *self);
void shell_linker_deinit(t_allocator *allocator, t_shell_linker *self);
t_shell_linker *shell_linker_destroy(t_allocator *allocator, t_shell_linker *self);

struct s_shell_env
{
	t_allocator *allocator;
	char       **envp;
	t_table     *vars;
	t_vector    *keys;
	t_vector    *value;
};

t_shell_env *shell_env_create(t_allocator *allocator);
void  shell_env_init(t_allocator *allocator, t_shell_env *self, char **envp);
bool  shell_env_del(t_shell_env *self, char *key);
char *shell_env_get(t_shell_env *self, char *key);
bool  shell_env_set(t_shell_env *self, char *key, char *value);
void  shell_env_print_one(t_shell_env *self, char *key);
void  shell_env_print_all(t_shell_env *self);
void  shell_env_deinit(t_allocator *allocator, t_shell_env *self);
t_shell_env *shell_env_destroy(t_allocator *allocator, t_shell_env *self);

struct s_shell_input
{
	t_allocator *allocator;
	char        *prompt;
	char        *line;
};

t_shell_input *shell_input_create(t_allocator *allocator);
void shell_input_init(t_allocator *allocator, t_shell_input *self, char *prompt);
char          *shell_input_get(t_shell_input *self);
void           shell_input_deinit(t_allocator *allocator, t_shell_input *self);
t_shell_input *shell_input_destroy(t_allocator *allocator, t_shell_input *self);

struct s_shell_prompt
{
	t_allocator *allocator;
	char        *prompt;
};

t_shell_prompt *shell_prompt_create(t_allocator *allocator);
void shell_prompt_init(t_allocator *allocator, t_shell_prompt *self, char *pwd);
char *shell_prompt_get(t_shell_prompt *self);
void  shell_prompt_deinit(t_allocator *allocator, t_shell_prompt *self);
t_shell_prompt *shell_prompt_destroy(t_allocator *allocator, t_shell_prompt *self);

struct s_builtin_cd
{
	t_allocator *allocator;
};

t_builtin_cd *builtin_cd_create(t_allocator *allocator);
t_builtin_cd *builtin_cd_destroy(t_allocator *allocator, t_builtin_cd *self);

struct s_builtin_echo
{
	t_allocator *allocator;
};

t_builtin_echo *builtin_echo_create(t_allocator *allocator);
t_builtin_echo *builtin_echo_destroy(t_allocator *allocator, t_builtin_echo *self);

struct s_builtin_env
{
	t_allocator *allocator;
};

t_builtin_env *builtin_env_create(t_allocator *allocator);
t_builtin_env *builtin_env_destroy(t_allocator *allocator, t_builtin_env *self);

struct s_builtin_export
{
	t_allocator *allocator;
};

t_builtin_export *builtin_export_create(t_allocator *allocator);
t_builtin_export *builtin_export_destroy(t_allocator *allocator, t_builtin_export *self);

struct s_builtin_unset
{
	t_allocator *allocator;
};

t_builtin_unset *builtin_unset_create(t_allocator *allocator);
t_builtin_unset *builtin_unset_destroy(t_allocator *allocator, t_builtin_unset *self);

struct s_builtin_pwd
{
	t_allocator *allocator;
};

t_builtin_pwd *builtin_pwd_create(t_allocator *allocator);
t_builtin_pwd *builtin_pwd_destroy(t_allocator *allocator, t_builtin_pwd *self);

struct s_builtin_exit
{
	t_allocator *allocator;
};

t_builtin_exit *builtin_exit_create(t_allocator *allocator);
t_builtin_exit *builtin_exit_destroy(t_allocator *allocator, t_builtin_exit *self);

void _minishell_assert(bool condition, char *function);
void _minishell_expect(bool condition, char *function);

// misc
bool from_string_to_key_value_pair(t_allocator *allocator, char *source, char **key, char **value);
int32_t key_compare(uintptr_t k1, uintptr_t k2);
#endif
