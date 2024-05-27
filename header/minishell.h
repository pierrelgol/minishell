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

#define ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALNUM "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define DEBUG_LINE "echo \"Hello World\";"

extern int64_t g_signal;

typedef struct s_token_payload   t_token_payload;
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

#ifndef DIRECT_IO
#define DIRECT_IO 0
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
	KIND_ID,
	KIND_ASSIGNMENT,
	KIND_CMD,
	KIND_QUOTE_START,
	KIND_QUOTE_END,
	KIND_DQUOTE_START,
	KIND_DQUOTE_END,
	KIND_KW,
	KIND_VAR,
	KIND_SPC,
	KIND_PIPE,
	KIND_RED_IN,
	KIND_RED_OUT,
	KIND_RED_APPEND,
	KIND_RED_HERE_DOC,
	KIND_SCOLON,
	KIND_AND,
	KIND_OR,
	KIND_FILE,
	KIND_PATH,
	KIND_BUILTIN,
	KIND_ARG,
	KIND_ERR,
} t_token_kind;

struct s_token_payload
{
	t_allocator *allocator;
};

t_token_payload *token_payload_create(t_allocator *allocator);
void token_payload_init(t_allocator *allocator, t_token_payload *self);
void token_payload_deinit(t_allocator *allocator, t_token_payload *self);
t_token_payload *token_payload_destroy(t_allocator *allocator, t_token_payload *self);

struct s_token
{
	t_token_kind kind;
	uintptr_t    extra;
	char        *str;
	uint64_t     len;
};

t_token *token_create(t_allocator *allocator);
void     token_init(t_allocator *allocator, t_token *self);
void     token_deinit(t_allocator *allocator, t_token *self);
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
/// DEBUG ONLY
void         shell_env_print(t_shell_env *env);
t_shell_env *shell_env_destroy(t_allocator *allocator, t_shell_env *self);

struct s_shell_prompt
{
	t_allocator *allocator;
	t_shell_env *env;
	char        *prompt;
};

t_shell_prompt *shell_prompt_create(t_allocator *allocator, t_shell_env *env);
void            shell_prompt_init(t_allocator *allocator, t_shell_prompt *self);
char           *shell_prompt_get(t_shell_prompt *self);
void shell_prompt_deinit(t_allocator *allocator, t_shell_prompt *self);
void shell_prompt_print(t_shell_prompt *prompt);
t_shell_prompt *shell_prompt_destroy(t_allocator *allocator, t_shell_prompt *self);

struct s_shell_input
{
	t_allocator    *allocator;
	t_shell_prompt *prompt;
	t_shell        *shell;
	char           *line;
};

t_shell_input *shell_input_create(t_allocator *allocator, t_shell *shell, t_shell_prompt *prompt);
void           shell_input_init(t_allocator *allocator, t_shell_input *self);
char          *shell_input_get(t_shell_input *self);
void           shell_input_deinit(t_allocator *allocator, t_shell_input *self);
void           shell_input_print(t_shell_input *self);
t_shell_input *shell_input_destroy(t_allocator *allocator, t_shell_input *self);

struct s_shell_tokenizer
{
	t_allocator   *allocator;
	t_shell_input *input;
	char         **split;
	t_vector      *output;
	t_bitset       bitset;
};

t_shell_tokenizer *shell_tokenizer_create(t_allocator *allocator, t_shell_input *input, char *delimiters);
void      shell_tokenizer_init(t_allocator *allocator, t_shell_tokenizer *self);
t_vector *shell_tokenizer_get(t_shell_tokenizer *self);
void      shell_tokenizer_print(t_shell_tokenizer *self);
void shell_tokenizer_deinit(t_allocator *allocator, t_shell_tokenizer *self);
t_shell_tokenizer *shell_tokenizer_destroy(t_allocator *allocator, t_shell_tokenizer *self);

struct s_shell_lexer
{
	t_allocator       *allocator;
	t_shell_tokenizer *tokenizer;
	t_iterator        *it;
};

t_shell_lexer *shell_lexer_create(t_allocator *allocator, t_shell_tokenizer *tokenizer);
void shell_lexer_init(t_allocator *allocator, t_shell_lexer *self);
void shell_lexer_lex(t_shell_lexer *self);

void shell_lexer_identify_whitespace(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_builtins(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_keywords(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_operators(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_id(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_path(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_file(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_quotes(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_assignment(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_error(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_cmd(t_shell_lexer *self, t_iterator *it);
void shell_lexer_identify_arg(t_shell_lexer *self, t_iterator *it);

t_iterator    *shell_lexer_get(t_shell_lexer *self);
void           shell_lexer_deinit(t_allocator *allocator, t_shell_lexer *self);
void           shell_lexer_print(t_shell_lexer *self);
t_shell_lexer *shell_lexer_destroy(t_allocator *allocator, t_shell_lexer *self);

struct s_shell_linker
{
	t_allocator   *allocator;
	t_shell_lexer *lexer;
	t_shell_env   *env;
	char         **paths;
	t_vector      *payload_vector;
	t_iterator    *it;
};

t_shell_linker *shell_linker_create(t_allocator *allocator, t_shell_env *env, t_shell_lexer *lexer);
void        shell_linker_init(t_allocator *allocator, t_shell_linker *self);
t_iterator *shell_linker_get(t_shell_linker *linker);
char *shell_linker_make_path(t_allocator *allocator, const char *prefix, const char *suffix);
bool shell_linker_test_path_cmd(t_allocator *allocator, const char *prefix, const char *suffix);
bool shell_linker_test_path_file_or_dir(t_allocator *allocator, const char *prefix, const char *suffix);
void shell_linker_deinit(t_allocator *allocator, t_shell_linker *self);
t_shell_linker *shell_linker_destroy(t_allocator *allocator, t_shell_linker *self);

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

// debug
char *direct_io(t_shell *shell);
char *getkind(t_token_kind kind);

bool is_path(const char *str);
bool is_file(const char *str);
bool is_identifier(int32_t ch);
bool is_identifier_start(int32_t ch);

#endif
