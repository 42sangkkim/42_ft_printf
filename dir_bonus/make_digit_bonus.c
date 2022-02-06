/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_digit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:23:40 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/06 15:29:27 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	make_addr(char *buf, unsigned long value)
{
	const char		*hex = "0123456789abcdef";
	int				offset;
	unsigned long	div;

	if (!value)
		buf[0] = '0';
	offset = 0;
	div = 0x1000000000000000;
	while (div)
	{
		if (value / div)
			buf[offset++] = hex[value / div % 16];
		div /= 16;
	}
}
