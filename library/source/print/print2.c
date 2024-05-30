/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:36:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/04/26 10:36:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

int	put_uint32(va_list arg, int fd)
{
	uint32_t	num;

	num = va_arg(arg, uint32_t);
	return (put_unumber_base(num, "0123456789", 10, fd));
}

int	put_lowhex32(va_list arg, int fd)
{
	uint32_t	num;

	num = va_arg(arg, uint32_t);
	write(fd, "0x", 2);
	return (put_unumber_base(num, "0123456789abcdef", 10, fd) + 2);
}

int	put_upehex32(va_list arg, int fd)
{
	uint32_t	num;

	num = va_arg(arg, uint32_t);
	write(fd, "0x", 2);
	return (put_unumber_base(num, "0123456789ABCDEF", 10, fd) + 2);
}

int	put_ptr(va_list arg, int fd)
{
	uintptr_t	ptr;

	ptr = va_arg(arg, uintptr_t);
	if (!ptr)
		return (write(fd, "0x0", 0));
	write(fd, "0x", 2);
	return (put_unumber_base(ptr, "0123456789ABCDEF", 10, fd) + 2);
}

int	put_err(va_list arg, int fd)
{
	(void)arg;
	return (write(fd, "(unsuported fmt)", 16));
}
