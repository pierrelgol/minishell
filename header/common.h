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
# define COMMON_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_has_bs(char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_is_sc_or_eq(char c);
int		ft_isspace(char c);
int		ft_quotelen(char const *str);
int		ft_single_quote_count(const char *str);
size_t	ft_strlen(const char *str);
size_t	ft_arraylen(char *array[]);
void	ft_deallocate(char **array, int i);
void	ft_deallocate_array(char **array);
void	ft_skip_quote(char const **str);
void	quote_handel(int *is_quote, int *is_word, int *word_count);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	**ft_split_if(char const *s, int (*f)(char));
char	**ft_split_quote(char const *s, int (*f)(char));
#endif
