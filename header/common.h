/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:30:29 by bifernan          #+#    #+#             */
/*   Updated: 2024/04/11 12:36:09 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_builtins_cd     t_builtins_cd;
typedef struct s_builtins_echo   t_builtins_echo;
typedef struct s_builtins_env    t_builtins_env;
typedef struct s_builtins_export t_builtins_export;
typedef struct s_builtins_unset  t_builtins_unset;
typedef struct s_builtins_pwd    t_builtins_pwd;
typedef struct s_builtins        t_builtins;
typedef struct s_environment     t_environment;
typedef struct s_hashmap         t_hashmap;
typedef struct s_hashmap_entry   t_hashmap_entry;
typedef struct s_input           t_input;
typedef struct s_exec            t_exec;
typedef struct s_parser          t_parser;
typedef struct s_lexer           t_lexer;
typedef struct s_linker          t_linker;
typedef struct s_prompt          t_prompt;
typedef struct s_shell           t_shell;
typedef struct s_token           t_token;
typedef struct s_token_2         t_token_2;
typedef struct s_tokenizer       t_tokenizer;

int    ft_has_bs(char *str);
int    ft_atoi(const char *str);
int    ft_isdigit(int c);
int    ft_is_sc_or_eq(char c);
int    ft_isspace(char c);
int    ft_quotelen(char const *str);
int    ft_single_quote_count(const char *str);
size_t ft_strlen(const char *str);
size_t ft_arraylen(char *array[]);
void   ft_deallocate(char **array, int i);
void   ft_deallocate_array(char **array);
void   ft_skip_quote(char const **str);
void   quote_handel(int *is_quote, int *is_word, int *word_count);
void  *ft_memset(void *s, int c, size_t n);
char  *ft_itoa(int n);
char **ft_split(char const *s, char c);
char **ft_split_if(char const *s, int (*f)(char));
char **ft_split_quote(char const *s, int (*f)(char));
#endif
