/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putd_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:47:52 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 16:36:42 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	putd(t_format format, long value)
{
	char	*buffer;
	int		print_len;

	buffer = make_d(value, format.flags);
	if (buffer && format.flags.precision && format.precision > digitlen(buffer))
		buffer = match_precision(buffer, format.precision);
	if (buffer && format.flags.width && format.width > strlen(buffer))
		buffer = match_width_decimal(buffer, format.width, format.flags);
	if (!buffer)
		return (-1);
	print_len = write(1, buffer, strlen(buffer));
	free(buffer);
	return (print_len);
}

char	*make_d(long value, t_flags flags)
{
	char	*buffer;
	int		offset;

	buffer = calloc(22, sizeof(char));
	if (!buffer)
		return (NULL);
	offset = 0;
	if (value < 0)
		buffer[offset++] = '-';
	else if (flags.plus)
		buffer[offset++] = '+';
	else if (flags.space)
		buffer[offset++] = ' ';
	if (value < 0)
		build_ul(buffer + offset, -value);
	else
		build_ul(buffer + offset, value);
	return (buffer);
}
