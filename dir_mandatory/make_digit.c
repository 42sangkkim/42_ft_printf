/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:07:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 11:19:41 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	make_deci(char *buffer, long value)
{
	int	offset;

	offset = 0;
	if (value / 10)
		offset += make_deci(buffer, value / 10);
	else if (value < 0)
		buffer[offset++] = '-';
	if (value < 0)
		value *= -1;
	buffer[offset++] = (value % 10) + '0';
	return (offset);
}

void	make_lowerhex(char *buffer, unsigned long value)
{
	const char	*hex = "0123456789abcdef";
	int			offset;
	int			div;

	offset = 0;
	div = 8 * 8;
	while (div)
	{
		div -= 8;
		if (value >> div)
			buffer[offset++] = hex[(value >> div) % 16];
	}
}

void	make_upperhex(char *buffer, unsigned long value)
{
	const char	*hex = "0123456789ABCDEF";
	int			offset;
	int			div;

	offset = 0;
	div = 8 * 8;
	while (div)
	{
		div -= 8;
		if (value >> div)
			buffer[offset++] = hex[(value >> div) % 16];
	}
}
