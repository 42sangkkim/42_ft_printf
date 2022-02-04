/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:09:06 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 15:06:00 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

const char	*build_buffer(t_format format, char c);

int	put_char(t_format format, char c)
{
	char	*buffer;
	int		write_return;

	if (format.width <= 1)
		return (write(1, &c, 1));
	else if (format.flags.minus)
		return (c_space(format.width, c));
	else if (format.flags.zero)
		return (zero_c(format.width, c));
	else
		return (space_c(format.width, c));
}

int	c_space(int width, char c)
{
	char	*buffer;
	int		printed;

	buffer = calloc(width + 1, sizeof(char));
	if (!buffer)
		return (0);
	mamset(buffer, ' ', width);
	buffer[0] = c;
	printed = write(1, buffer, strlen(buffer));
	free(buffer);
	return (printed);
}

int	zero_c(int width, char c)
{
	char	*buffer;
	int		printed;

	buffer = calloc(width + 1, sizeof(char));
	if (!buffer)
		return (0);
	mamset(buffer, '0', width);
	buffer[width - 1] = c;
	printed = write(1, buffer, strlen(buffer));
	free(buffer);
	return (printed);
}

int	zero_c(int width, char c)
{
	char	*buffer;
	int		printed;

	buffer = calloc(width + 1, sizeof(char));
	if (!buffer)
		return (0);
	mamset(buffer, ' ', width);
	buffer[width - 1] = c;
	printed = write(1, buffer, strlen(buffer));
	free(buffer);
	return (printed);
}
