/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:01:57 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/24 11:34:16 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = (long)n;
	if (number < 0)
	{
		number *= -1;
		ft_putchar_fd('-', fd);
	}
	if (number > 9)
	{
		ft_putnbr_fd((number / 10), fd);
		ft_putchar_fd((number % 10) + '0', fd);
	}
	if (number <= 9)
		ft_putchar_fd(number + '0', fd);
}

/*#include <stdlib.h>

int	main(int argc, char *argv[])
{
	ft_putnbr_fd(atoi(argv[1]), 1);
	return (0);
}*/
