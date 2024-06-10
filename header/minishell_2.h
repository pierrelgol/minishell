#ifndef MINISHELL_2_H
# define MINISHELL_2_H

# include "stdio.h"
# include "../libft/includes/common.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
#include <sys/wait.h>
# define COLOR_GREEN "\033[0;32m"
# define COLOR_RESET "\033[0m"

typedef enum e_token_type
{
	UNKNOWN,
	IDENTIFIER,
	MINUS,
	PIPE,
	DOT,
	LEFT_PARENTHESIS,
	RIGHT_PARENTHESIS,
	INPUT_REDIRECT,
	OUTPUT_REDIRECT,
	APPEND_REDIRECT,
	AMPERSAND,
	SEMICOLON,
	EXCLAMATION,
	KEYWORD,
	PATH,
	GUESS_FILE,
	EXISTING_FILE,
	UNEXISTING_FILE,
	CMD_OPTION,
	DOUBLE_QUOTE,
	SINGLE_QUOTE,
	CMD,
	CMD_ARG,
	HERE_DOC,
	HD_DELIM,
	SPC,
	DOLLAR,
}	t_token_type;

/*
typedef struct s_command
{
	t_token *parent_operation; //pipe ou autre quoi
	char	*command;
	char	**args;
	int	input_source;
	int	output_source;
}	t_command;*/

typedef enum	e_effective_output_type
{
	NONE,
	APPEND,
	TRUNC,
}	o_type; //seule la derniere redirectiction est effectuee : dans "ls > 1 > 2 > 3", 1, 2 et 3 
		// sont crees mais 1 et 2 sont vides, on doit savoir si la derniere redirection est un '>' ou un '>>'

typedef struct s_token_2
{
	t_token_type type;
	int	id;
	char	*value;
	int	size;
	struct s_token_2 *next;
	struct s_token_2 *prev;
	struct s_token_2 *left_quote;
	struct s_token_2 *right_quote;
}	t_token_2;

typedef struct tokenList
{
	int	size;
	t_token_2	*head;
	t_token_2	*tail;
}	tokenList;

typedef struct s_cmd
{
	int	id;
	int	fd_array[3];
	o_type	output_type;
	char	**cmd_vector;
	char	**input_vector;
	char	**output_vector;
	char	**o_append_vector;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct cmdTable
{
	int	size;
	int	pipe_number;
	int	**pipe_array;
	int	pipe_index;
	t_cmd	*head;
	t_cmd	*tail;
}	cmdTable;

typedef struct s_minishell
{
	char	*path_variable;
	char	**tokens;
	char	*line;
	char	*extended_line;
	char	*sep;
	char	**envp;
	tokenList	**token_array;
	tokenList	*token_list;
	cmdTable	*cmd_table;
}	t_minishell;

/***********ERRORS.C************/

void	expect(t_minishell *minishell, void *ptr, char *message);


/***********TOKENLIST************/

tokenList	*token_list_new(void);
void	token_list_clear(tokenList *self);
void	token_list_destroy(tokenList *self);
void	token_list_add_back(tokenList *tklist, char *value);
void	token_list_print_value(tokenList *self);
void	token_list_print_type(tokenList *self);

/*********TOKENTYPE*************/

int	is_keyword(t_token_2 *token);
int	is_keyword_2nd_check(t_token_2 *token);
int	is_keyword_1st_check(t_token_2 *token);
void	set_token_type(t_token_2 *token);
int	is_identifier(t_token_2 *token);

/***********MISC****************/

char	*get_path_variable(char *envp[]);
void	display_prompt(void);
void	remove_new_line(t_minishell *self);
void	display_parsing_info(t_minishell *sh);

/**********MINISHELL************/

t_minishell *allocate_minishell(void);
void	set_path_variable(t_minishell *minishell, char *envp[]);
t_minishell	*minishell_create(char *envp[]);
void	minishell_destroy(t_minishell *self);
void	minishell_loop(t_minishell *self);
void	minishell_get_extended_line(t_minishell *self);
void	tokeniser(t_minishell *self);

/*********ARRAY****************/
void	print_array(char **array);
int	array_len(char	**array);
void	free_array(char ***array);

/*********STRING+PRE+TREATMENT*************/

int	string_extended_len(char *str, char *sep);
void	string_extend_copy(char *dest, char *source, char *sep, char wedge);
char	*string_add_delimiter(char *str, char *sep, char wedge);

/***************UTILS***************/

char	*ft_strtok(char *str, char sep);
int	ft_issep(char c, char *sep);

/*************PARSING****************/
//parser_check.c
int	test_if_executable(t_minishell *sh, t_token_2 *token);
char	*make_exec_path(char *path_variable, char *value);
char	**get_path_vector(char *path_variable);
int	is_executable(char *path);
//parser.c
void	guesser(t_minishell *sh);

/************CMD_TABLE*****************/

cmdTable	*cmdTable_create(void);
void	cmdTable_destroy(cmdTable *self);
int	get_cmd_vector_size(t_token_2 *cmd_token);
char	**get_cmd_vector(t_token_2 *cmd_token, t_minishell *sh);
void	cmdTable_add_back(cmdTable *self, t_minishell *sh, t_token_2 *cmd_token, tokenList *tklist);
void	fill_cmd_table(t_minishell *sh);
void	cmdTable_clear(cmdTable *self);

/***********EXECUTE***************/

 void	execute_command(t_minishell *self);


/**********TOKEN_ARRAY*******************/

int	count_pipe(tokenList *self);
int	tokenArray_tokenList_count(tokenList *self); //we have pipe_count + 1 tokenLists to make
tokenList	**tokenArray_init(t_minishell *sh);
void	tokenArray_destroy(tokenList **token_array);
int	tokenArray_size(tokenList **array);
void	set_tokenArray(t_minishell *sh);
void	tokenCopy_add_back(tokenList *tklist, t_token_2 *token);
void	fill_tokenArray(t_minishell *sh);
void	print_tokenArray(tokenList **array);

/************PRE_EXEC*******************/


void	fill_cmd_table(t_minishell *sh);
void	print_cmd_table(t_minishell *sh);

/*********CMD_TABLE_CREATION***********/

int	vector_size(tokenList *tklist, t_token_type type);
void	fill_io_vector(tokenList *tklist, char **io_vector, t_token_type type);
char	**io_vector_init(tokenList *tklist, t_token_type type);
void	io_vector_destroy(char **io_vector);

/******PROCESSES*************/


int	pipe_has_been_used(int pipe_uses);
void	open_pipe(cmdTable *self);
void	actualize_pipe_index(cmdTable *self);
void	parent_process(t_minishell *sh);
int	is_first_command(t_cmd *self);
int	is_last_command(t_cmd *self);
int	is_the_only_cmd(t_cmd *self);
int	is_in_middle_cmd(t_cmd *self);
void	child_process(t_minishell *sh, cmdTable *cmd_table, t_cmd *self);
void	execute(t_minishell *sh, t_cmd *self);

/********PIPE_AND_EXEC************/

int	pipe_count(cmdTable *self);
int	open_file_append_mode(char *filename);
int	open_file_input_mode(char *filename);
int	open_file_output_mode(char *filename);
int	open_all_input_files_and_get_last(char	**input_vector);
int	open_all_output_files_and_get_last(char	**output_vector);
int	open_all_append_files_and_get_last(char	**o_append_vector);

/**********PIPE_MANAGEMENT*************/

void	create_pipe_array(t_minishell *sh, cmdTable *self);
void	destroy_pipe_array(cmdTable *self);

/************DEBBUG********************/

void	cmd_table_monitoring(cmdTable *self);

/*************OUTPUT_TYPE************/

o_type	get_effective_output_type(tokenList *self);

/***********QUOTER*************/

void	quoter(t_minishell *self);
void	remove_all_space_tokens(tokenList *tklist);
void	remove_token(tokenList *tklist, t_token_2 *self);
int	tokenList_has_quotes(tokenList *tklist);


void	link_token_to_quotes(tokenList *self);
void	find_left_quote(t_token_2 *self);
void	find_right_quote(t_token_2 *self);
void	refresh_token_id(tokenList *self);

void	display_token_id(tokenList *self);
void	display_token_quotes(tokenList *self);

int	is_enclosed_token(t_token_2 *self);
int	is_space_token(t_token_2 *self);
int	is_unclosed_space_token(t_token_2 *self);
void	remove_all_unclosed_space_tokens(tokenList *self);

/**************QUOTER_2******************/

void	set_left_and_right_quote(t_token_2 *self, t_token_2 *opening_quote, t_token_2 *enclosing_quote);
t_token_2 *get_enclosing_quote(t_token_2 *self);
t_token_2 *get_next_quote(t_token_2 *self);
t_token_2	*get_first_quote(tokenList *self);
int	token_is_hard_quoted(t_token_2 *self);

/**************EXPANDER*************/

int	has_dollar_token(tokenList *self);
void	expander(t_minishell *self);
char	*find_value(t_minishell *sh, t_token_2 *key);
void	replace_key_by_value(t_minishell *sh, t_token_2 *key);
int	is_dollar_token(t_token_2 *self);
void	remove_all_dollar_tokens(tokenList *self);

#endif
