/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:00:33 by bifernan          #+#    #+#             */
/*   Updated: 2024/04/05 16:02:57 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_findindex(char *b1, int b1_size)
{
	size_t	index;

	if (!b1 || b1_size <= 0)
		return (-1);
	index = 0;
	while (index < (size_t)b1_size)
	{
		if (b1[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int	ft_b2handler(char *b2, char *b1, char **line, t_val *s_v)
{
	s_v->b_b2_len = 0;
	while (b2[s_v->b_b2_len] != 0)
		s_v->b_b2_len++;
	if (!s_v->b_b2_len)
		return (0);
	s_v->is_empty_b2 = 0;
	s_v->b_ni = ft_findindex(b2, s_v->b_b2_len);
	if (s_v->b_ni == -1)
		return (s_v->b_b2_len);
	s_v->b_line_size = s_v->b_ni + 2;
	*line = (char *)malloc(sizeof(char) * s_v->b_line_size);
	if (!*line)
		return (-1);
	ft_snc(*line, b2, s_v->b_ni + 1, 1);
	if ((size_t)s_v->b_ni + 1 < s_v->b_b2_len)
	{
		ft_snc(b1, &b2[s_v->b_ni + 1], (s_v->b_b2_len - s_v->b_ni -1), 1);
		ft_memset(b2, 0, s_v->b_b2_len);
		ft_snc(b2, b1, (s_v->b_b2_len - s_v->b_ni - 1), 1);
	}
	else
		ft_memset(b2, 0, s_v->b_b2_len);
	return (0);
}

int	ft_get_list(int fd, char *b2, t_val *s_v)
{
	while (s_v->ni == -1 && s_v->reaturn == BUFFER_SIZE)
	{
		ft_dlstadd_front(s_v->dlst, s_v->b1, BUFFER_SIZE);
		s_v->reaturn = read(fd, s_v->b1, BUFFER_SIZE);
		s_v->ni = ft_findindex(s_v->b1, BUFFER_SIZE);
	}
	if ((!s_v->reaturn && !s_v->dlst->dlst_len && !s_v->b2_size) \
	|| s_v->reaturn < 0)
		return (-1);
	if (s_v->dlst->dlst_len && s_v->reaturn == 0 && s_v->ni == -1)
	{
		s_v->l_s = s_v->dlst->dlst_len * BUFFER_SIZE + s_v->b2_size + 1;
		return (1);
	}
	if (s_v->ni == -1)
		s_v->len = s_v->reaturn;
	else
		s_v->len = s_v->ni + 1;
	s_v->l_s = s_v->dlst->dlst_len * BUFFER_SIZE + s_v->len + s_v->b2_size + 1;
	if ((s_v->ni < s_v->reaturn -1) && s_v->is_empty_b2 && s_v->ni != -1)
	{
		ft_snc(b2, &s_v->b1[s_v->ni + 1], (s_v->reaturn - s_v->ni - 1), 1);
		s_v->is_empty_b2 = 0;
	}
	return (0);
}

int	ft_get_line(char *b2, t_val *s_v)
{
	s_v->line = (char *)malloc(sizeof(char) * s_v->l_s);
	if (!s_v->line)
	{
		ft_dlstclear(s_v->dlst);
		return (-1);
	}
	if (s_v->b2_size)
	{
		ft_snc(s_v->line, b2, s_v->b2_size, 1);
		ft_memset(b2, 0, BUFFER_SIZE);
	}
	s_v->temp = NULL;
	if (s_v->dlst->dlst_len != 0)
		s_v->temp = s_v->dlst->p_tail;
	while (s_v->temp != NULL)
	{
		ft_snc(&s_v->line[s_v->b2_size], s_v->temp->c, (size_t)BUFFER_SIZE, 1);
		s_v->b2_size += BUFFER_SIZE;
		s_v->temp = s_v->temp->p_prev;
	}
	ft_snc(&s_v->line[s_v->b2_size], s_v->b1, s_v->len, 1);
	if (s_v->ni < s_v->reaturn && !s_v->is_empty_b2 && s_v->ni != -1)
		ft_snc(b2, &s_v->b1[s_v->ni + 1], (s_v->reaturn - s_v->ni - 1), 1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	b2[BUFFER_SIZE];
	t_val		s_v;

	s_v.line = NULL;
	s_v.is_empty_b2 = 1;
	s_v.len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (s_v.line);
	ft_memset(s_v.b1, 0, BUFFER_SIZE);
	s_v.b2_size = ft_b2handler(b2, s_v.b1, &s_v.line, &s_v);
	if (s_v.b2_size == -1)
		return (NULL);
	if (s_v.line != NULL)
		return (s_v.line);
	s_v.dlst = ft_dlstnew();
	if (!s_v.dlst)
		return (NULL);
	s_v.reaturn = read(fd, s_v.b1, BUFFER_SIZE);
	s_v.ni = ft_findindex(s_v.b1, BUFFER_SIZE);
	if (ft_get_list(fd, b2, &s_v) == -1)
		return (ft_dlstclear(s_v.dlst), NULL);
	if (ft_get_line(b2, &s_v) == -1)
		return (NULL);
	ft_dlstclear(s_v.dlst);
	return (s_v.line);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	*line;
	
	if (argc != 3)
		return (0);
	i = atoi(argv[2]);
	fd = open(argv[1], O_RDONLY);
	while (i > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i--;
	}
	close(fd);
	return (0);
}*/
