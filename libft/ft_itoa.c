/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:44:54 by sangkkim          #+#    #+#             */
/*   Updated: 2021/11/26 17:33:02 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_numlen(int n)
{
	size_t	len;

	len = (n < 0);
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*mem;

	len = get_numlen(n);
	mem = malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	if (n < 0)
		*mem = '-';
	*(mem + len) = 0;
	if (n == 0)
		*mem = '0';
	while (n)
	{
		len -= 1;
		*(mem + len) = abs(n % 10) + '0';
		n /= 10;
	}
	return (mem);
}
