/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putd_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:27:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/07 14:41:10 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	putd(t_format format, long value)
{
	char	*buffer;
	char	prefix;

	buffer = ltoa_with_prefix(value, format.flags.space, format.flags.plus);
	if (format.flags.precision)
		if (format.precision > digitlen(buffer))
			expand();
	else
		if (!format.flags.minus && format.flags.zero
			&& format.width > strlen(buffer))
			expend_with_zero();
	if (format.flags.width && format.width > strlen(buffer))
		match_width(&buffer, format.width, format.flags.minus);
	// print_buf(buffer);
	free(buffer);
}

const char	*ltoa_with_prefix(long value, int space, int plus)
{
	char	*buffer;
	int		offset;

	buffer = calloc(22, sizeof(char));
	offset = 0;
	if (value < 0)
		buffer[offset++] = '-';
	else if (plus)
		buffer[offset++] = '+';
	else if (space)
		buffer[offset++] = ' ';
	if (value < 0)
		make_ulong(buffer + offset, -value);
	else
		make_ulong(buffer + offset, value);
	return (buffer);
}

void	match_width(char **buf, int width, int align)
{
	char	*new_buf;
	int		string_len;
	int		space_len;

	new_buf = calloc(width + 1, sizeof(char));
	if (!new_buf)
		return (NULL);
	string_len = strlen(*buf);
	space_len = width - string_len;
	if (align)
	{
		strcat(new_buf, *buf);
		memset(new_buf + string_len, ' ', space_len);
	}
	else
	{
		memset(new_buf, ' ', space_len);
		strcat(new_buf, *buf);
	}
	free(*buf);
	buf = &new_buf;
}
