/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:50:10 by sangkkim          #+#    #+#             */
/*   Updated: 2021/11/25 20:59:23 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		upper;
	int		lower;
	char	digit;

	upper = n / 10;
	lower = n % 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		upper = -upper;
		lower = -lower;
	}
	if (upper)
		ft_putnbr_fd(upper, fd);
	digit = lower + '0';
	ft_putchar_fd(digit, fd);
}
