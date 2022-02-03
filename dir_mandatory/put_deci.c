/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_deci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:30:19 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/03 23:37:48 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	put_deci(long value)
{
	char	buffer[21];

	bzero(buffer, 21);
	if (value < 0)
	{
		buffer[0] = '-';
		make_deci(buffer + 1, -value);
	}
	else
		make_deci(buffer, value);
	return (write(1, buffer, strlen(buffer)));
}

void	make_deci(char *buffer, unsigned long value)
{
	
}
