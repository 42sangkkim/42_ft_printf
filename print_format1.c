/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:24:30 by sangkkim          #+#    #+#             */
/*   Updated: 2022/01/21 20:12:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_charactor(char c);
int	print_string(char *s);
int	print_pointer(unsigned long ptr);
int	print_decimal(int value);
int	print_u_decimal(unsigned int value);
int	print_hex(unsigned int value, char notation);

int	ft_strlen(const char *s);

int	print_format(char format, unsigned long arg)
{
	if (format == 'c')
		return (print_charactor((char)arg));
	else if (format == 's')
		return (print_string((char *)arg));
	else if (format == 'p')
		return (print_pointer((unsigned long)arg));
	else if (format == 'd')
		return (print_decimal((int)arg));
	else if (format == 'i')
		return (print_decimal((int)arg));
	else if (format == 'u')
		return (print_u_decimal((unsigned int)arg));
	else if (format == 'x')
		return (print_hex((unsigned int)arg, 'x'));
	else
		return (print_hex((unsigned int)arg, 'X'));
}

int	print_charactor(char c)
{
	return (write(1, &c, 1));
}

int	print_string(char *s)
{
	int	len;

	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	else
	{
		len = ft_strlen(s);
		write(1, s, len);
		return (len);
	}
}
