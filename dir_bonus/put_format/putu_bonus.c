/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:47:52 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 19:30:43 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	putu(t_format format, unsigned long value)
{
	int		print_len;
	char	*buffer;

	buffer = make_u(value, format.flags);
	if (buffer && format.flags.precision && format.precision > digitlen(buffer))
		buffer = match_precision_decimal(buffer, format.precision);
	if (buffer && format.flags.width && format.width > strlen(buffer))
		buffer = match_width_decimal(buffer, format.width, format.flags);
	if (!buffer)
		return (-1);
	print_len = write(1, buffer, strlen(buffer));
	free(buffer);
	return (print_len);
}

char	*make_u(long value, t_flags flags)
{
	char	*buffer;

	buffer = calloc(21, sizeof(char));
	if (!buffer)
		return (NULL);
	build_ul(buffer, value);
	return (buffer);
}
