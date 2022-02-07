/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:51:22 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/07 14:41:14 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	putu(t_format format, unsigned long value)
{
	char	*buffer;
	char	prefix;

	buffer = ultoa(value);
	if (format.flags.precision && format.precision > strlen(buffer))
		expand(&buffer, format.precision);
	if (!format.flags.precision && !format.flags.minus && format.flags.zero
		&& format.width > strlen(buffer))
		expend(&buffer, format.width);
	if (format.flags.width && format.width > strlen(buffer))
		match_width(&buffer, format.width, format.flags.minus);
	// print_buf(buffer);
	free(buffer);
}

const char	*ultoa(unsigned long value)
{
	char	*buffer;
	int		offset;

	buffer = calloc(22, sizeof(char));
	if (value < 0)
		make_uint(buffer, -value);
	else
		make_uint(buffer, value);
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
