/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putp_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:48:16 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/06 20:50:18 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// puts_bonus.c
void	puts(t_format format, const char *s);

void	make_addr(char *buf, unsigned long value);

void	putp(t_format format, void *p)
{
	char	buffer[20];

	bzero(buffer, 20);
	strcat(buffer, "0x");
	make_addr(buffer, (unsigned long)p);
	puts(format, buffer);
}

void	make_addr(char *buf, unsigned long value)
{
	const char		*hex = "0123456789abcdef";
	int				offset;
	unsigned long	div;

	if (!value)
		buf[0] = '0';
	offset = 0;
	div = 0x1000000000000000;
	while (div)
	{
		if (value / div)
			buf[offset++] = hex[value / div % 16];
		div /= 16;
	}
}
