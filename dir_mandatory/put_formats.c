/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_formats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:50:36 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 12:51:53 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		make_deci(char *buffer, long value);
void	make_lowerhex(char *buffer, unsigned long value);
void	make_upperhex(char *buffer, unsigned long value);

int	put_char(char c)
{
	return (write(1, &c, 1));
}

int	put_str(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, strlen(s)));
}

int	put_addr(void *ptr)
{
	unsigned long	addr;
	char			buffer[30];

	addr = (unsigned long)ptr;
	bzero(buffer, 30);
	buffer[0] = '0';
	buffer[1] = 'x';
	make_lowerhex(buffer + 2, addr);
	return (write(1, buffer, strlen(buffer)));
}

int	put_deci(long value)
{
	char	buffer[30];

	bzero(buffer, 30);
	make_deci(buffer, value);
	return (write(1, buffer, strlen(buffer)));
}

int	put_hex(unsigned long value, char hex_case)
{
	char	buffer[30];

	bzero(buffer, 30);
	if (hex_case == 'x')
		make_lowerhex(buffer, value);
	else
		make_upperhex(buffer, value);
	return (write(1, buffer, strlen(buffer)));
}
