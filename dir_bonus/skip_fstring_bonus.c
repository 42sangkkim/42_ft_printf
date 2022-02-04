/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_fstring_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:25:45 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 14:09:24 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	skip_format(const char *f_string);
int	skip_string(const char *f_string);
int	is_format(const char c);
int	is_string(const char c);

int	skip_fstring(const char *f_string)
{
	if (*f_string == '%')
		return (skip_format(f_string));
	else
		return (skip_string(f_string));
}

int	skip_format(const char *f_string)
{
	int	skip_len;

	skip_len = 1;
	while (is_format(f_string[skip_len]))
		skip_len += 1;
	if (f_string[skip_len])
		skip_len += 1;
	return (skip_len);
}

int	skip_string(const char *f_string)
{
	int	skip_len;

	skip_len = 0;
	while (is_string(f_string[skip_len]))
		skip_len += 1;
	return (skip_len);
}

int	is_format(const char c)
{
	return (c && (isdigit(c) || strchr("-.# +", c)));
}

int	is_string(const char c)
{
	return (c && c != '%');
}
