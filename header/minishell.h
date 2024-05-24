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

typedef struct s_shell_parser    t_shell_parser;
typedef struct s_shell_lexer     t_shell_lexer;
typedef struct s_shell_tokenizer t_shell_tokenizer;
typedef struct s_shell_prompt    t_shell_prompt;
typedef struct s_shell_input     t_shell_input;
typedef struct s_shell_env       t_shell_env;
typedef struct s_token_iter      t_token_iter;
typedef struct s_token           t_token;
typedef struct s_shell           t_shell;

#ifndef MAX_TOKENS
#define MAX_TOKENS 128
#endif

typedef enum e_token_kind
{
	KIND_NO_KIND = 0,       // No specific kind
	KIND_END_OF_TOK,        // for the iterator to stop
	KIND_WHITESPACE,        // WHITESPACE
	KIND_UNKNOWN,           // Unknown token
	KIND_KEYWORD,           // Shell keyword
	KIND_PATH,              // File or directory path
	KIND_FILE,              // File name
	KIND_IDENTIFIER,        // General identifier
	KIND_SEMI_COLON,        // Semicolon (;)
	KIND_BUILTIN_MAYBE_ARG, // Built-in command with maybe some arguments
	KIND_BUILTIN_NO_ARG,    // Built-in command with no arguments
	KIND_BUILTIN_ARG,       // Built-in command with arguments
	KIND_CMD_MAYBE_ARG,     // Command with maybe some arguments
	KIND_CMD_NO_ARG,        // Command with no arguments
	KIND_CMD_ARG,           // Command with arguments
	KIND_ARG,               // General argument
	KIND_EXPAND_VAR,        // $
	KIND_AND,               // Logical AND (&&)
	KIND_OR,                // Logical OR (||)
	KIND_PIPE,              // Pipe (|)
	KIND_LEFT_REDIR,        // Input redirection (<)
	KIND_RIGHT_REDIR,       // Output redirection (>)
	KIND_HEREDOC,           // Here-document (<<)
	KIND_APPEND,            // Output redirection with append (>>)
	KIND_BACKGROUND,        // Background process (&)
	KIND_SUBSHELL_START,    // Start of subshell (()
	KIND_SUBSHELL_END,      // End of subshell ())
	KIND_COMMENT,           // Comment (#)
	KIND_ASSIGNMENT,        // Variable assignment (=)
	KIND_NEWLINE            // Newline (\n)
} t_token_kind;

// @TODO
t_vector *token_vector_create(t_allocator *allocator, uint64_t size);
t_vector *token_vector_clear(t_allocator *allocator, t_vector *vector);
t_vector *token_vector_destroy(t_allocator *allocator, t_vector *vector);

struct s_token
{
	t_token_kind kind;
	char        *str;
	uint64_t     len;
	uintptr_t    extra;
};

t_token *token_create(t_allocator *allocator);
t_token *token_set_str(t_allocator *allocator, t_token *self, char *string);
t_token *token_set_kind(t_token *self, t_token_kind kind);
t_token *token_set_extra(t_token *self, uintptr_t extra);
t_token *token_clear(t_allocator *allocator, t_token *self);
bool     token_is_kind(t_token *token, t_token_kind kind);
bool     token_contains_scalar(t_token *t1, int32_t scalar);
bool     token_contains_any(t_token *t1, t_bitset *any);
bool     token_starts_with_scalar(t_token *t1, int32_t scalar);
bool     token_starts_with_any(t_token *t1, t_bitset *any);
bool     token_ends_with_scalar(t_token *t1, int32_t scalar);
bool     token_ends_with_any(t_token *t1, t_bitset *any);
bool     token_is_eql_str(t_token *t1, char *str);
bool     token_is_eql_len(t_token *t1, uint64_t len);
bool token_is_eql_extra(t_token *t1, uint64_t extra, bool(t_cmp)(uintptr_t x1, uintptr_t x2));
bool     token_print(t_token *tok);
t_token *token_destroy(t_allocator *allocator, t_token *tok);

struct s_token_iter
{
	t_allocator *allocator;
	t_vector    *tokens;
	uint64_t     capacity;
	uint64_t     index;
	uint64_t     count;
};
// @ TODO
t_token_iter *iter_create(t_allocator *allocator, t_vector *tokens);
void          iter_update_count(t_token_iter *iter);
void          iter_reset_start(t_token_iter *iter);
uint64_t      iter_eat(t_token_iter *iter, uint64_t n);
t_token      *iter_match_kind(t_token_iter *iter, t_token_kind kind);
t_token      *iter_match_str(t_token_iter *iter, char *str);
uint64_t      iter_skip_kind(t_token_iter *iter, t_token_kind kind);
uint64_t      iter_skip_str(t_token_iter *iter, char *str);
t_token      *iter_peek_next(t_token_iter *iter);
t_token      *iter_peek_curr(t_token_iter *iter);
t_token      *iter_peek_prev(t_token_iter *iter);
bool          iter_is_eof(t_token_iter *iter);
t_token_iter *iter_destroy(t_token_iter *self);

struct s_shell
{
	t_allocator       *allocator;
	t_shell_env       *environment;
	t_shell_prompt    *prompt;
	t_shell_input     *input;
	t_shell_tokenizer *tokenizer;
	t_shell_lexer     *lexer;
	t_shell_parser    *parser;
	t_token_iter      *iter;
	// @TODO
	t_vector          *tokens;
	char              *line;
};

t_shell *shell_create(t_allocator *allocator, int32_t argc, char **argv, char **envp);
void     shell_run(t_shell *shell);
void     shell_clear(t_shell *shell);
t_shell *shell_destroy(t_shell *shell);

struct s_shell_env
{
	t_allocator *allocator;
	t_table     *variables;
	t_list      *keys;
	t_list      *protected_keys;
	int32_t      argc;
	char       **argv;
	char       **envp;
};

t_shell_env *shell_env_create(t_allocator *allocator, int32_t argc, char **argv, char **envp);
void env_init_default(t_shell_env *env, t_allocator *allocator, t_table *variables, char **envp);
void env_init_customs(t_shell_env *env, t_allocator *allocator, t_table *variables, char **envp);
bool         env_contains(t_shell_env *env, char *key);
bool         env_protected_remove(t_shell_env *env, char *key);
bool         env_remove(t_shell_env *env, char *key);
char        *env_get(t_shell_env *env, char *key);
char        *env_protected_get(t_shell_env *env, char *key, char *def);
bool         env_protected_put(t_shell_env *env, char *key, char *value);
bool         env_put(t_shell_env *env, char *key, char *value);
int32_t      key_compare(uintptr_t k1, uintptr_t k2);
bool         env_print_one(t_shell_env *env, char *key);
bool         env_print_all(t_shell_env *env, bool sort);
t_shell_env *shell_env_destroy(t_shell_env *env);

struct s_shell_prompt
{
	t_allocator *allocator;
	t_shell_env *env;
	char        *prompt;
	char        *path;
	char        *symbol;
	char        *color;
};

t_shell_prompt *shell_prompt_create(t_allocator *allocator, t_shell_env *env);
void            prompt_build(t_shell_prompt *prompt);
char           *prompt_get(t_shell_prompt *prompt);
void            prompt_clear(t_shell_prompt *prompt);
t_shell_prompt *shell_prompt_destroy(t_shell_prompt *prompt);

struct s_shell_input
{
	t_shell_prompt *prompt;
	t_allocator    *allocator;
	char           *line;
	int64_t         signal;
};

t_shell_input *shell_input_create(t_allocator *allocator, t_shell_prompt *prompt);
char          *input_get(t_shell_input *input);
void           input_clear(t_shell_input *input);
t_shell_input *shell_input_destroy(t_shell_input *input);

struct s_shell_tokenizer
{
	t_allocator  *allocator;
	t_bitset      delimiters;
	char         *input;
	t_token_iter *output;
};

t_shell_tokenizer *shell_tokenizer_create(t_allocator *allocator, t_token_iter *iter);
t_token_iter *tokenizer_tokenize(t_shell_tokenizer *tokenizer, char *input, char *delimiters);
void               tokenizer_clear(t_shell_tokenizer *tokenizer);
t_shell_tokenizer *shell_tokenizer_destroy(t_shell_tokenizer *tokenizer);

struct s_shell_lexer
{
	t_allocator  *allocator;
	t_token_iter *output;
};

t_shell_lexer *shell_lexer_create(t_allocator *allocator, t_token_iter *iter);
t_token_iter  *lexer_lex(t_shell_lexer *lexer);
void           lexer_clear(t_shell_lexer *lexer);
t_shell_lexer *shell_lexer_destroy(t_shell_lexer *lexer);

struct s_shell_parser
{
	t_allocator  *allocator;
	t_token_iter *output;
};

t_shell_parser *shell_parser_create(t_allocator *allocator, t_token_iter *iter);
void           parser_clear(t_shell_parser *parser);
t_shell_parser *shell_parser_destroy(t_shell_parser *parser);

char **allocator_destroy_split(t_allocator *allocator, char **split);

#endif
