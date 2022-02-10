/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:29:14 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/10 12:08:35 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format.h"
#include "../ft_printf.h"

char	*make_c_buffer(t_format format, unsigned char c);
char	*make_s_buffer(t_format format, char *s);
char	*make_p_buffer(t_format format, void *p);
char	*make_d_buffer(t_format format, int d);

char	*make_u_buffer(t_format format, unsigned int u);
char	*make_x_buffer(t_format format, unsigned int x);
void	make_hex(char *buffer, unsigned long value);
void	make_lhex(char *buffer, unsigned long value);
void	make_uint(char *buffer, unsigned int value);

char	*make_buffer(t_format format, va_list *ap)
{
	if (format.specifier == 'c')
		return (make_c_buffer(format, va_arg(*ap, int)));
	if (format.specifier == 's')
		return (make_s_buffer(format, va_arg(*ap, char *)));
	if (format.specifier == 'p')
		return (make_p_buffer(format, va_arg(*ap, void *)));
	if (format.specifier == 'd' || format.specifier == 'i')
		return (make_d_buffer(format, va_arg(*ap, int)));
	if (format.specifier == 'u')
		return (make_u_buffer(format, va_arg(*ap, unsigned int)));
	if (format.specifier == 'x' || format.specifier == 'X')
		return (make_x_buffer(format, va_arg(*ap, unsigned int)));
	if (format.specifier == '%')
		return (make_c_buffer(format, '%'));
	return (NULL);
}

char	*make_c_buffer(t_format format, unsigned char c)
{
	char	*buffer;

	buffer = calloc(2, sizeof(char));
	if (buffer)
		buffer[0] = c;
	return (buffer);
}

char	*make_s_buffer(t_format format, char *s)
{
	return (strdup(s));
}

char	*make_p_buffer(t_format format, void *p)
{
	char	*buffer;

	buffer = calloc(19, sizeof(char));
	if (buffer)
	{
		buffer[0] = '0';
		buffer[1] = 'x';
		make_hex(buffer + 2, (unsigned long)p);
	}
	return (buffer);
}

char	*make_d_buffer(t_format format, int d)
{
	char	*buffer;

	buffer = calloc(12, sizeof(char));
	if (buffer)
	{
		if (d < 0)
		{
			buffer[0] = '-';
			make_uint(buffer + 1, -d);
		}
		else
		{
			make_uint(buffer, d);
		}
	}
	return (buffer);
}
