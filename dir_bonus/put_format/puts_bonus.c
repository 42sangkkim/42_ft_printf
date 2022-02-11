/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:30:35 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 13:28:47 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	puts(t_format format, const char *s)
{
	int			print_len;
	char		*buffer;

	buffer = make_s(s);
	if (buffer && format.flags.precision && format.precision < strlen(buffer))
		match_precision(buffer, format.precision);
	if (buffer && format.flags.width && format.width > strlen(buffer))
		match_width(buffer, format.width, format.flags.minus);
	if (!buffer)
		return (-1);
	print_len = write(1, buffer, strlen(buffer));
	free(buffer);
	return (print_len);
}

char	*make_s(const char *s)
{
	const char	*null_s = "(null)";

	if (!s)
		return (strdup(null_s));
	else
		return (strdup(s));
}

void	match_precision(char **buf, int precision)
{
	(*buf)[precision] = '\0';
}

void	match_width(char **buf, int width, int minus)
{
	char	*new_buf;
	int		string_len;
	int		space_len;

	new_buf = calloc(width + 1, sizeof(char));
	if (!new_buf)
		return (NULL);
	string_len = strlen(*buf);
	space_len = width - string_len;
	if (minus)
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
