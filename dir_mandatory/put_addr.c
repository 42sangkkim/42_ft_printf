/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_addr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:14:28 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/03 23:29:02 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	make_hex(char *buffer, unsigned long value);

int	put_addr(void *ptr)
{
	unsigned long	addr;
	char			buffer[19];

	addr = (unsigned long)ptr;
	bzero(buffer, 19);
	buffer[0] = '0';
	buffer[1] = 'x';
	make_hex(buffer + 2, addr);
	return (write(1, buffer, strlen(buffer)));
}

void	make_hex(char *buffer, unsigned long value)
{
	const char	*hex = "0123456789abcdef";
	int			offset;

	offset = 16;
	while (offset--)
	{
		if (value >> (offset * 8))
			*buffer++ = hex[(value >> (offset * 8)) & 0xFF];
	}
}
