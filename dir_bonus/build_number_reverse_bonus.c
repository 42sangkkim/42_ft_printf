/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_number_reverse_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:11:47 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/08 19:11:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	build_long_reverse(char *buffer, long value)
{
	int	offset;

	if (value < 0)
	{
		while (1)
		{
			buffer[offset++] = -value % 10 + '0';
			value /= 10;
			if (!value)
				break ;
		}
		buffer[offset++] = '-';
	}
	else
	{
		while (1)
		{
			buffer[offset++] = value % 10 + '0';
			value /= 10;
			if (!value)
				break ;
		}
	}
	buffer[offset] = '\0';
}

void	build_ulong_reverse(char *buffer, unsigned long value)
{
	int	offset;

	offset = 0;
	while (1)
	{
		buffer[offset++] = value % 10 + '0';
		value /= 10;
		if (!value)
			break ;
	}
	buffer[offset] = '\0';
}

void	build_hex_reverse(char *buffer, unsigned long value)
{
	const char		*hex = "0123456789abcdef";
	int				offset;

	offset = 0;
	buffer[offset++] = value % 16 + '0';
	value /= 16;
	while (value)
	{
		buffer[offset++] = hex[value % 16];
		value /= 16;
	}
	buffer[offset] = '\0';
}

void	build_lhex_reverse(char *buffer, unsigned long value)
{
	const char		*hex = "0123456789ABCDEF";
	int				offset;

	offset = 0;
	buffer[offset++] = value % 16 + '0';
	value /= 16;
	while (value)
	{
		buffer[offset++] = hex[value % 16];
		value /= 16;
	}
	buffer[offset] = '\0';
}
