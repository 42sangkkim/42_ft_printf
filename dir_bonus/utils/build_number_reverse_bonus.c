/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_number_reverse_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:11:47 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 19:16:23 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	build_ul(char *buffer, unsigned long value)
{
	unsigned long	div;

	div = 10000000000000000000;
	while (div)
	{
		if (value / div)
			*buffer++ = value / div % 10 + '0';
		div /= 10;
	}
}

void	build_hex(char *buffer, unsigned long value)
{
	const char		*hex = "0123456789abcdef";
	unsigned long	div;

	div = 0x1000000000000000;
	while (div)
	{
		if (value / div)
			*buffer++ = hex[value / div % 16];
		div /= 16;
	}
}

void	build_lhex(char *buffer, unsigned long value)
{
	const char		*hex = "0123456789ABCDEF";
	unsigned long	div;

	div = 0x1000000000000000;
	while (div)
	{
		if (value / div)
			*buffer++ = hex[value / div % 16];
		div /= 16;
	}
}
