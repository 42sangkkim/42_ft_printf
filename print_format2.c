/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:24:59 by sangkkim          #+#    #+#             */
/*   Updated: 2022/01/21 20:17:12 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_pointer(unsigned long ptr)
{
	const char	*notation = "0123456789abcdef";
	int			len;
	int			i;

	len = write(1, "0x", 2);
	if (!ptr)
		len += write(1, "0", 1);
	else
	{
		i = 16;
		while (i--)
		{
			if (ptr >> (4 * i))
				len += write(1, &(notation[(ptr >> (4 * i)) % 16]), 1);
		}
	}
	return (len);
}

int	print_decimal(int value)
{
	int		len;
	char	digit;

	len = 0;
	if (value / 10)
		len = print_decimal(value / 10);
	else if (value < 0)
		len += write(1, "-", 1);
	if (value < 0)
		digit = -(value % 10) + '0';
	else
		digit = (value % 10) + '0';
	len += write(1, &digit, 1);
	return (len);
}

int	print_u_decimal(unsigned int value)
{
	int		len;
	char	digit;

	len = 0;
	if (value / 10)
		len = print_decimal(value / 10);
	digit = (value % 10) + '0';
	len += write(1, &digit, 1);
	return (len);
}

int	print_hex(unsigned int value, char notation)
{
	const char	*lower_hex = "0123456789abcdef";
	const char	*upper_hex = "0123456789ABCDEF";
	int			len;

	len = 0;
	if (value / 16)
		len += print_hex(value / 16, notation);
	if (notation == 'x')
		len += write(1, &(lower_hex[value % 16]), 1);
	else
		len += write(1, &(upper_hex[value % 16]), 1);
	return (len);
}
