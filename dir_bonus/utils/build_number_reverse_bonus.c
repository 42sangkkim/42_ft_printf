/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_number_reverse_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:11:47 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/08 21:03:45 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*build_long_reverse(long value, t_flags flags)
{
	char	*buffer;
	int		offset;

	if (value < 0)
	{
		buffer = build_ulong_reverse(-value);
		if (!buffer)
			return (NULL);
		*(strchr(buffer, '\0')) = '-';
		return (buffer);
	}
	else
	{
		buffer = build_ulong_reverse(value);
		if (!buffer)
			return (NULL);
		if (flags.plus)
			*(strchr(buffer, '\0')) = '+';
		else if (flags.space)
			*(strchr(buffer, '\0')) = ' ';
		return (buffer);
	}
}

char	*build_ulong_reverse(unsigned long value)
{
	char	*buffer;
	int		offset;

	buffer = calloc(22, sizeof(char));
	if (!buffer)
		return (NULL);
	offset = 0;
	while (1)
	{
		buffer[offset++] = value % 10 + '0';
		value /= 10;
		if (!value)
			return (buffer);
	}
}

char	*build_hex_reverse(unsigned long value, int prefix)
{
	const char		*hex = "0123456789abcdef";
	char			*buffer;
	int				offset;

	buffer = calloc(19, sizeof(char));
	if (!buffer)
		return (NULL);
	offset = 0;
	buffer[offset++] = value % 16 + '0';
	value /= 16;
	while (value)
	{
		buffer[offset++] = hex[value % 16];
		value /= 16;
	}
	if (prefix)
		strcat(buffer, "x0");
	return (buffer);
}

char	*build_lhex_reverse(unsigned long value, int prefix)
{
	const char		*hex = "0123456789ABCDEF";
	char			*buffer;
	int				offset;

	buffer = calloc(19, sizeof(char));
	if (!buffer)
		return (NULL);
	offset = 0;
	buffer[offset++] = value % 16 + '0';
	value /= 16;
	while (value)
	{
		buffer[offset++] = hex[value % 16];
		value /= 16;
	}
	if (prefix)
		strcat(buffer, "x0");
	return (buffer);
}
