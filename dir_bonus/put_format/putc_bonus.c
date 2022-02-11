/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:09:06 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 13:21:25 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*match_width(int width, unsigned char c, int minus);

int	putc(t_format format, unsigned char c)
{
	char	*buffer;

	if (format.flags.width && format.width > 1)
	{
		buffer = match_width(format.width, c, format.flags.minus);
		if (!buffer)
			reutrn (-1);
		return (write(1, buffer, format.width));
	}
	else
		return (write(1, &c, 1));
}

static char	*match_width(int width, unsigned char c, int minus)
{
	char	*buffer;

	buffer = calloc(width, sizeof(char));
	if (!buffer)
		return (NULL);
	memset(buffer, ' ', width);
	if (minus)
		buffer[0] = 'c';
	else
		buffer[width - 1] = 'c';
	return (buffer);
}
