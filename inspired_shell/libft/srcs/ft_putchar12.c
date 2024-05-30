/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar12.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:36:07 by bifernan          #+#    #+#             */
/*   Updated: 2024/04/05 14:38:31 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar12(int c, int *char_count, t_directives s_dir)
{
	int	to_print;

	to_print = ' ';
	if (ft_is_minusf(s_dir.flags))
	{
		ft_putchar1(c, char_count);
		s_dir.field_width -= 1;
		while (s_dir.field_width > 0)
		{
			ft_putchar1(to_print, char_count);
			s_dir.field_width--;
		}
	}
	else
	{
		s_dir.field_width -= 1;
		while (s_dir.field_width > 0)
		{
			ft_putchar1(to_print, char_count);
			s_dir.field_width--;
		}
		ft_putchar1(c, char_count);
	}
}
