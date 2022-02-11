/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putp_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:48:16 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 19:26:40 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*make_p(unsigned long value);
char	*match_width(char *buffer, int width, t_flags flags);

void	putp(t_format format, void *p)
{
	int		print_len;
	char	*buffer;

	buffer = make_p((unsigned long)p);
	if (buffer && format.flags.width && format.width > strlen(buffer))
		buffer = match_width(buffer, format.width, format.flags);
	if (!buffer)
		return (-1);
	print_len = write(1, buffer, strlen(buffer));
	free(buffer);
	return (print_len);
}

char	*make_p(unsigned long value)
{
	char	*buffer;

	buffer = calloc(19, sizeof(char));
	if (buffer)
	{
		buffer[0] = '0';
		buffer[1] = 'x';
		build_hex(buffer + 2, value);
	}
	return (buffer);
}
