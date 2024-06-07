/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:35:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/30 12:35:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/slib.h"

int	fprint(int32_t fd, const char *fmt, ...)
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
			count += print_fmt_parser(&fmt[++index]).fmt(arguments, fd);
			index += arg_len(&fmt[index]);
		}
		else
			count += write(fd, &fmt[index++], 1);
	}
	va_end(arguments);
	return (count);
}
