/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:55:28 by bifernan          #+#    #+#             */
/*   Updated: 2024/04/05 16:01:03 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "common.h"

typedef struct s_node
{
	struct s_node	*p_next;
	struct s_node	*p_prev;
	char			c[BUFFER_SIZE];
}	t_node;

typedef struct s_dlist
{
	size_t	dlst_len;
	t_node	*p_head;
	t_node	*p_tail;
}	t_dlist;

typedef struct s_v
{
	char	b1[BUFFER_SIZE];
	char	*line;
	size_t	l_s;
	ssize_t	b2_size;
	ssize_t	ni;
	ssize_t	lindex;
	ssize_t	len;
	ssize_t	reaturn;
	size_t	b_b2_len;
	ssize_t	b_ni;
	size_t	b_line_size;
	t_dlist	*dlst;
	t_node	*temp;
	int		is_empty_b2;
}	t_val;	

char	*get_next_line(int fd);
t_dlist	*ft_dlstnew(void);
void	ft_snc(char *dst, const char *src, size_t n, int is_line);
void	ft_dlstadd_front(t_dlist *dlst, char *c, int b1_size);
void	ft_dlstclear(t_dlist *dlst);
size_t	ft_findindex(char *b1, int b1_size);
int		ft_b2handler(char *b2, char *b1, char **line, t_val *s_v);
int		ft_get_list(int fd, char *b2, t_val *s_v);
int		ft_get_line(char *b2, t_val *s_v);

#endif
