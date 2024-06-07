/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:32:55 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 12:32:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

t_printer	print_fmt_parser(const char *fmt)
{
	int	ch[2];

	if (fmt[0] != 0)
		ch[1] = fmt[1];
	ch[0] = fmt[0];
	if (ch[0] == '%' || ch[0] == 'c')
		return ((t_printer){.fmt = put_char});
	else if (ch[0] == 's')
		return ((t_printer){.fmt = put_string});
	else if (ch[0] == 'd' || ch[0] == 'i')
		return ((t_printer){.fmt = put_int32});
	else if (ch[0] == 'u')
		return ((t_printer){.fmt = put_uint32});
	else if (ch[0] == 'x')
		return ((t_printer){.fmt = put_lowhex32});
	else if (ch[0] == 'X')
		return ((t_printer){.fmt = put_upehex32});
	else if (ch[0] == 'p')
		return ((t_printer){.fmt = put_ptr});
	else if (ch[0] == 'l' && ch[1] == 'd')
		return ((t_printer){.fmt = put_ilong64});
	else if ((ch[0] == 'l' || ch[0] == 'z') && ch[1] == 'u')
		return ((t_printer){.fmt = put_ulong64});
	return ((t_printer){.fmt = put_err});
}

int32_t	arg_len(const char *fmt)
{
	int32_t	ch;
	int32_t	i;

	i = 0;
	while (fmt[i])
	{
		ch = fmt[i];
		if (ch == '%' || ch == 'c' || ch == 's' || ch == 'd')
			++i;
		else if (ch == 'i' || ch == 'u' || ch == 'x' || ch == 'X')
			++i;
		else if (ch == 'z' || ch == 'p' || ch == 'l')
			++i;
		else
			return (i);
	}
	return (0);
}

int	print(const char *fmt, ...)
{
	va_list		arguments;
	uint64_t	index;
	uint64_t	count;

	index = 0;
	count = 0;
	va_start(arguments, fmt);
	while (fmt[index])
	{
		if (fmt[index] == '%')
		{
			count += print_fmt_parser(&fmt[++index]).fmt(arguments, 1);
			index += arg_len(&fmt[index]);
		}
		else
			count += write(1, &fmt[index++], 1);
	}
	va_end(arguments);
	return (count);
}

int32_t	put_unumber_base(uint64_t num, const char *base, int32_t radix, int fd)
{
	uint64_t	i;
	uint64_t	len;
	char		result[64];

	len = 0;
	i = 0;
	while (num > 0)
	{
		result[i] = base[num % radix];
		num /= radix;
		i++;
	}
	if (i == 0)
		len += write(fd, "0", 1);
	else
	{
		while (i > 0)
			len += write(fd, &result[--i], 1);
	}
	return (len);
}

int32_t	put_inumber_base(int64_t num, const char *base, int32_t radix, int fd)
{
	uint64_t	i;
	uint64_t	len;
	char		result[64];

	len = 0;
	if (num < 0)
	{
		len += write(fd, "-", 1);
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		result[i] = base[num % radix];
		num /= radix;
		i++;
	}
	if (i == 0)
		len += write(fd, "0", 1);
	else
	{
		while (i > 0)
			len += write(fd, &result[--i], 1);
	}
	return (len);
}
