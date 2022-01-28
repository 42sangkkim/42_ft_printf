/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:04:31 by sangkkim          #+#    #+#             */
/*   Updated: 2021/12/10 12:30:31 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define L_MAX_UPPER 922337203685477580
#define LONG_MAX 0x7FFFFFFFFFFFFFFFL
#define LONG_MIN 0x8000000000000000L

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\r' || c == '\n'
		|| c == '\f' || c == '\v' || c == ' ');
}

static long	ft_strtol(const char *str)
{
	long		sign;
	long		value;

	while (ft_isspace(*str))
		str++;
	sign = 1 - (2 * (*str == '-'));
	if (*str == '-' || *str == '+')
		str ++;
	value = 0;
	while (ft_isdigit(*str))
	{
		if (value > (long)LONG_MAX / 10
			|| (value == (long)LONG_MAX / 10 && *str > '7'))
			return (LONG_MAX);
		else if (value < (long)LONG_MIN / 10
			|| (value == (long)LONG_MIN / 10 && *str > '8'))
			return (LONG_MIN);
		value = (value * 10) + sign * (*str - '0');
		str++;
	}
	return (value);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str));
}
