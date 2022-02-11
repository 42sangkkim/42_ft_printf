/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_formats2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:43:38 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 12:43:40 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	make_hex(char *buffer, unsigned long value);
void	make_lhex(char *buffer, unsigned long value);
void	make_uint(char *buffer, unsigned int value);

int	putu(unsigned int u)
{
	char	buffer[11];
	int		print_len;

	bzero(buffer, 11);
	make_uint(buffer, u);
	print_len = write(1, buffer, strlen(buffer));
	return (print_len);
}

int	putx(t_format format, unsigned int x)
{
	char	buffer[9];
	int		print_len;

	bzero(buffer, 9);
	if (format.specifier == 'x')
		make_hex(buffer, x);
	else
		make_lhex(buffer, x);
	print_len = write(1, buffer, strlen(buffer));
	return (print_len);
}

void	make_hex(char *buffer, unsigned long value)
{
	const char		*hex = "0123456789abcdef";
	int				offset;
	unsigned long	div;

	offset = 0;
	div = 0x1000000000000000;
	while (div)
	{
		if (value / div)
			buffer[offset++] = hex[value / div % 16];
		div /= 16;
	}
	if (offset == 0)
		buffer[offset] = '0';
}

void	make_lhex(char *buffer, unsigned long value)
{
	const char		*hex = "0123456789ABCDEF";
	int				offset;
	unsigned long	div;

	offset = 0;
	div = 0x1000000000000000;
	while (div)
	{
		if (value / div)
			buffer[offset++] = hex[value / div % 16];
		div /= 16;
	}
	if (offset == 0)
		buffer[offset] = '0';
}

void	make_uint(char *buffer, unsigned int value)
{
	int				offset;
	unsigned int	div;

	offset = 0;
	div = 1000000000;
	while (div)
	{
		if (value / div)
			buffer[offset++] = (value / div % 10) + '0';
		div /= 10;
	}
	if (offset == 0)
		buffer[offset] = '0';
}
