/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:30:35 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 10:19:24 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	puts(t_format format, const char *s)
{
	int			slen;
	char		*buf;

	buf = copy_s(s);
	if (buf && format.flags.precision && format.precision < strlen(buf))
		match_precision(buf, format.precision);
	if (buf && format.flags.width && format.width > strlen(buf))
		match_width(buf, format.width, format.flags.minus);
	// put_buffer(buf);
	free(buf);
}

char	*copy_s(const char *s)
{
	const char	*null_s = "(null)";
	char		*copy;

	if (!s)
		copy = strdup(null_s);
	else
		copy = strdup(s);
	return (copy);
}

void	match_precision(char **buf, int precision)
{
	(*buf)[precision] = '\0';
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
