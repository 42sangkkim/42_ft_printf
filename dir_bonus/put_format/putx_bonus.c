/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putx_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:15:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 19:38:02 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	putx(t_format format, unsigned int value)
{
	int		print_len;
	char	*buffer;

	buffer = make_x(value, format);
	if (buffer && format.flags.precision && format.precision > digitlen(buffer))
		buffer = match_precision_hex(buffer, format.precision);
	if (buffer && format.flags.width && format.width > strlen(buffer))
		buffer = match_width_hex(buffer, format.width, format.flags);
	if (!buffer)
		return (-1);
	print_len = write(1, buffer, strlen(buffer));
	free(buffer);
	return (print_len);
}

char	*make_x(unsigned int value, t_format format)
{
	char	*buffer;
	int		offset;

	buffer = calloc(11, sizeof(char));
	offset = 0;
	if (format.flags.sharp)
	{
		buffer[offset++] = '0';
		buffer[offset++] = 'x';
	}
	if (format.specifier == 'x')
		build_hex(buffer + offset, value);
	else
		build_lhex(buffer + offset, value);
	return (buffer);
}
