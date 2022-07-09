/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:15:22 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 01:04:55 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "format_bonus.h"

int		get_format(t_format *format, const char *str);
int		check_format(t_format format);
int		put_format(t_format, va_list *ap);

int		print_format(const char **str_p, va_list *ap);
int		print_string(const char **str_p);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			printed += print_format(&str, &ap);
		else
			printed += print_string(&str);
	}
	va_end(ap);
	return (printed);
}

int	print_format(const char **str_p, va_list *ap)
{
	t_format	format;
	int			len;
	int			printed;

	len = get_format(&format, *str_p);
	if (check_format(format) < 0)
		return (-1);
	*str_p += len;
	printed = put_format(format, ap);
	return (printed);
}

int	print_string(const char **str_p)
{
	int	len;
	int	printed;

	while ((*str_p)[len] && (*str_p)[len] != '%')
		len++;
	printed = (int)write(1, *str_p, len);
	if (len != printed)
		write(2, "[ERROR] write function error\n", 29);
	*str_p += len;
	return (printed);
}
