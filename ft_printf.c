/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:28:56 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 11:17:01 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"

// ft_printf.c [this]
int			print_format(const char **f_string, va_list *ap);
int			print_string(const char **f_string);
int			va_exit(va_list *ap, int exit_code);

// get_format.c
t_format	get_format(const char **f_string);
// check_format.c
int			check_format(t_format format);
// make_buffer.c
int			put_format(t_format format, va_list *ap);

int	ft_printf(const char *f_string, ...)
{
	int		temp_len;
	int		print_len;
	va_list	ap;

	print_len = 0;
	va_start(ap, f_string);
	while (*f_string)
	{
		if (*f_string == '%')
			temp_len = print_format(&f_string, &ap);
		else
			temp_len = print_string(&f_string);
		if (temp_len < 0)
			return (va_exit(&ap, -1));
		print_len += temp_len;
	}
	return (va_exit(&ap, print_len));
}

int	print_format(const char **f_string, va_list *ap)
{
	t_format	format;

	format = get_format(f_string);
	if (!check_format(format))
		return (-1);
	return (put_format(format, ap));
}

int	print_string(const char **f_string)
{
	char	*start;

	start = (char *)(*f_string);
	while (**f_string && **f_string != '%')
		*f_string += 1;
	return ((int)write(1, start, *f_string - start));
}

int	va_exit(va_list *ap, int exit_code)
{
	va_end(*ap);
	return (exit_code);
}
