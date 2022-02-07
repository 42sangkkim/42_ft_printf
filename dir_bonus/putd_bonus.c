/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putd_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:27:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/06 20:41:19 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	putd(t_format format, int value)
{
	char	*buffer;
	char	prefix;

	buffer = prefix_itoa(value, format.flags.plus, format.flags.space);
	if (buffer && format.flags.precision && format.precision > strlen(buffer))
		match_precision(&buffer, format.precision);
	if (buffer && format.flags.width && format.width > strlen(buffer))
		match_width(&buffer, format.width, format.flags.minus);
	//print_buffer(buffer);
	free(buffer);
}

const char	*prefix_itoa(int value, int space, int plus)
{
	char	*buffer;
	int		offset;

	buffer = calloc(12, sizeof(char));
	offset = 0;
	if (value < 0)
		buffer[offset++] = '-';
	else if (plus)
		buffer[offset++] = '+';
	else if (space)
		buffer[offset++] = ' ';
	if (value < 0)
		make_uint(buffer + offset, -value);
	else
		make_uint(buffer + offset, value);
	return (buffer);
}

const void	match_precision(char **buffer, int precision)
{
	char	*new_buf;

	if (strchr("- +", **buffer))
	{
		new_buf = calloc(precision + 2, sizeof(char));
		if (!new_buf)
		{
			new_buf[0] = **buffer;
			memset(new_buf + 1, '0', precision - strlen(*buffer + 1));
			strcat(new_buf, *buffer + 1);
		}
	}
	else
	{
		new_buf = calloc(precision + 1, sizeof(char));
		if (new_buf)
		{
			memset(new_buf, '0', precision - strlen(*buffer));
			strcat(new_buf, *buffer);
		}
	}
	free(*buffer);
	*buffer = new_buf;
}

const void	match_width(char **buffer, int width, int minus)
{
	char	*new_buf;
	int		number_len;
	int		space_len;

	new_buf = calloc(width + 1, sizeof(char));
	number_len = strlen(*buffer);
	space_len = width - number_len;
	if (new_buf && minus)
	{
		strcat(new_buf, *buffer);
		memset(new_buf + number_len, ' ', space_len);
	}
	else if (new_buf)
	{
		memset(new_buf, ' ', space_len);
		strcat(new_buf, *buffer);
	}
	free(*buffer);
	*buffer = new_buf;
}
