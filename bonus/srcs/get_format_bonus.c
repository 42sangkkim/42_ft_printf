/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:45:55 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 01:20:45 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "format_bonus.h"

int		set_flags(t_format *format, char c);
int		set_precision(t_format *format, const char *s);
int		set_width(t_format *format, const char *s);

int	get_format(t_format *format, const char *str)
{
	int	len;

	ft_bzero(format, sizeof(t_format));
	len = 1;
	while (str[len])
	{
		if (ft_strchr("-0# +", str[len]))
			len += set_flags(format, str[len]);
		else if (str[len] == '.')
			len += set_precision(format, str);
		else if (ft_isdigit(str[len]))
			len += set_width(format, str);
		else
		{
			format->specifier = str[len++];
			break ;
		}
		str++;
	}
	return (len);
}

int	set_flags(t_format *format, char c)
{
	if (c == '-')
		format->flags.minus = 1;
	else if (c == '0')
		format->flags.zero = 1;
	else if (c == '#')
		format->flags.hash = 1;
	else if (c == ' ')
		format->flags.space = 1;
	else if (c == '+')
		format->flags.plus = 1;
	return (1);
}

int	set_precision(t_format *format, const char *s)
{
	int	len;

	format->flags.precision = 1;
	len = 1;
	while (ft_isdigit(s[len]))
		len++;
	format->precision = ft_atoi(s + 1);
	return (len);
}

int	set_width(t_format *format, const char *s)
{
	int	len;

	format->flags.width = 1;
	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	format->width = ft_atoi(s);
	return (len);
}
