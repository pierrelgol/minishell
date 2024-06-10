/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:34 by bifernan          #+#    #+#             */
/*   Updated: 2024/04/05 16:04:38 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_snc(char *dst, const char *src, size_t n, int is_line)
{
	if (!dst || !src || !n)
		return ;
	while (n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	if (is_line)
		*dst = '\0';
}

t_dlist	*ft_dlstnew(void)
{
	t_dlist	*dlst;

	dlst = (t_dlist *)malloc(sizeof(t_dlist));
	if (!dlst)
		return (NULL);
	dlst->dlst_len = 0;
	dlst->p_head = NULL;
	dlst->p_tail = NULL;
	return (dlst);
}

void	ft_dlstadd_front(t_dlist *dlst, char *c, int b1_size)
{
	t_node	*node;

	if (!dlst || !c)
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	ft_snc(node->c, c, b1_size, 0);
	node->p_next = NULL;
	node->p_prev = NULL;
	if (dlst->dlst_len == 0)
	{
		dlst->p_head = node;
		dlst->p_tail = node;
	}
	else
	{
		node->p_prev = NULL;
		node->p_next = dlst->p_head;
		dlst->p_head->p_prev = node;
		dlst->p_head = node;
	}
	dlst->dlst_len += 1;
}

void	ft_dlstclear(t_dlist *dlst)
{
	t_node	*temp;

	if (!dlst)
		return ;
	if (!dlst->p_head)
	{
		free(dlst);
		return ;
	}
	else
	{
		temp = dlst->p_head;
		while (temp)
		{
			temp = temp->p_next;
			free(dlst->p_head);
			dlst->p_head = temp;
			dlst->dlst_len--;
		}
		free(dlst);
	}
}
