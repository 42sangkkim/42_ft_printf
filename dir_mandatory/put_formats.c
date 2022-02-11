/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_formats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:43:24 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 16:47:06 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		putc(unsigned char c);
int		puts(char *s);
int		putp(void *p);
int		putd(int d);

int		putu(unsigned int u);
int		putx(t_format format, unsigned int x);
void	make_hex(char *buffer, unsigned long value);
void	make_lhex(char *buffer, unsigned long value);
void	make_uint(char *buffer, unsigned int value);

int	put_format(t_format format, va_list *ap)
{
	if (format.specifier == 'c')
		return (putc(va_arg(*ap, int)));
	if (format.specifier == 's')
		return (puts(va_arg(*ap, char *)));
	if (format.specifier == 'p')
		return (putp(va_arg(*ap, void *)));
	if (format.specifier == 'd' || format.specifier == 'i')
		return (putd(va_arg(*ap, int)));
	if (format.specifier == 'u')
		return (putu(va_arg(*ap, unsigned int)));
	if (format.specifier == 'x' || format.specifier == 'X')
		return (putx(format, va_arg(*ap, unsigned int)));
	if (format.specifier == '%')
		return (putc('%'));
	return (-1);
}

int	putc(unsigned char c)
{
	return (write(1, &c, 1));
}

int	puts(char *s)
{
	const char	*null_str = "(null)";

	if (!s)
		return (write(1, null_str, 6));
	else
		return (write(1, s, strlen(s)));
}

int	putp(void *p)
{
	char	buffer[19];
	int		print_len;

	bzero(buffer, 19);
	buffer[0] = '0';
	buffer[1] = 'x';
	make_hex(buffer + 2, (unsigned long)p);
	print_len = write(1, buffer, strlen(buffer));
	return (print_len);
}

int	putd(int d)
{
	char	buffer[12];
	int		print_len;

	bzero(buffer, 12);
	if (d < 0)
	{
		buffer[0] = '-';
		make_uint(buffer + 1, -d);
	}
	else
	{
		make_uint(buffer, d);
	}
	print_len = write(1, buffer, strlen(buffer));
	return (print_len);
}
