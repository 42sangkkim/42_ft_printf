/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:21:40 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 11:25:30 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	make_lowerhex(char *buffer, unsigned long value);
void	make_upperhex(char *buffer, unsigned long value);

int	put_hex(unsigned long value, char hex_case)
{
	char	buffer[30];

	bzero(buffer, 30);
	if (hex_case == 'x')
		make_lowerhex(buffer, value);
	else
		make_upperhex(buffer, value);
	return (write(1, buffer, strlen(buffer)));
}
