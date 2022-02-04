/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:44:14 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 12:38:36 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_format(const char *f_string, va_list *ap);
int	print_string(const char *f_string);

int	put_char(char c);
int	put_str(char *s);
int	put_addr(void *ptr);
int	put_deci(long value);
int	put_hex(unsigned long value, char hex_case);

int	print_fstring(const char *f_string, va_list *ap)
{
	if (*f_string == '%')
		return (print_format(f_string + 1, ap));
	else
		return (print_string(f_string));
}

int	print_format(const char *f_string, va_list *ap)
{
	if (!*f_string)
		return (0);
	else if (*f_string == 'c')
		return (put_char(va_arg(*ap, int)));
	else if (*f_string == 's')
		return (put_str(va_arg(*ap, char *)));
	else if (*f_string == 'p')
		return (put_addr(va_arg(*ap, void *)));
	else if (*f_string == 'd' || *f_string == 'i')
		return (put_deci(va_arg(*ap, int)));
	else if (*f_string == 'u')
		return (put_deci(va_arg(*ap, unsigned int)));
	else if (*f_string == 'x' || *f_string == 'X')
		return (put_hex(va_arg(*ap, unsigned int), *f_string));
	else
		return (put_char(*f_string));
}

int	print_string(const char *f_string)
{
	size_t	len;

	len = 0;
	while (f_string[len] && f_string[len] != '%')
		len += 1;
	return (write(1, f_string, len));
}
