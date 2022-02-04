/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fstring_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:30:22 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 14:09:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int			print_format(const char *f_string, va_list *ap);
int			print_string(const char *f_string);
int			is_valid(t_format format);

t_format	get_format(const char *f_string);

int			put_char(t_format format, char c);
int			put_str(t_format format, char *s);
int			put_addr(t_format format, void *ptr);
int			put_deci(t_format format, long value);
int			put_hex(t_format format, unsigned long value, char hex_case);
int			put_default(t_format format, char c);

int	print_fstring(const char *f_string, va_list *ap)
{
	if (*f_string == '%')
		return (print_format(f_string + 1, ap));
	else
		return (print_string(f_string));
}

int	print_format(const char *f_string, va_list *ap)
{
	t_format	format;

	if (!*f_string)
		return (0);
	format = get_format(f_string);
	if (!is_valid(format))
		return (0);
	if (format.specifier == 'c')
		return (put_char(format, va_arg(*ap, int)));
	else if (format.specifier == 's')
		return (put_str(format, va_arg(*ap, char *)));
	else if (format.specifier == 'p')
		return (put_addr(format, va_arg(*ap, void *)));
	else if (format.specifier == 'd' || format.specifier == 'i')
		return (put_deci(format, va_arg(*ap, int)));
	else if (format.specifier == 'u')
		return (put_deci(format, va_arg(*ap, unsigned int)));
	else if (format.specifier == 'x' || format.specifier == 'X')
		return (put_hex(format, va_arg(*ap, unsigned int), *f_string));
	else
		return (put_default(format, *f_string));
}

int	print_string(const char *f_string)
{
	size_t	len;

	len = 0;
	while (f_string[len] && f_string[len] != '%')
		len += 1;
	return (write(1, f_string, len));
}

int	is_valid(t_format format)
{
	if (!format.specifier)
		return (0);
	if (format.specifier < 0)
		return (0);
	if (format.width < 0)
		return (0);
	return (1);
}
