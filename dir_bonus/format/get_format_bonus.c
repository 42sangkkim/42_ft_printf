/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:41:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 10:48:30 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	set_precision(t_format *format, const char **f_string);
void	set_width(t_format *format, const char **f_string);

t_format	get_format(const char **f_string)
{
	t_format	format;

	bzero(&format, sizeof(format));
	while (**f_string)
	{
		if (**f_string == '-')
			format.flags.minus = 1;
		else if (**f_string == '0')
			format.flags.zero = 1;
		else if (**f_string == '.')
			set_precision(&format, f_string);
		else if (isdigit(**f_string))
			set_width(&format, f_string);
		else if (**f_string == '#')
			format.flags.sharp = 1;
		else if (**f_string == ' ')
			format.flags.space = 1;
		else if (**f_string == '+')
			format.flags.plus = 1;
		else
			break ;
		*f_string += 1;
	}
	format.specifier = **f_string;
	if (**f_string)
		*f_string += 1;
	return (format);
}

void	set_precision(t_format *format, const char **f_string)
{
	int	offset;
	int	value;

	(*format).flags.precision = 1;
	offset = 1;
	value = 0;
	while (isdigit((*f_string)[offset]))
		value = value * 10 + ((*f_string)[offset++] - '0');
	(*format).precision = value;
}

void	set_width(t_format *format, const char **f_string)
{
	int	offset;
	int	value;

	(*format).flags.width = 1;
	offset = 0;
	value = 0;
	while (isdigit((*f_string)[offset]))
		value = value * 10 + ((*f_string)[offset++] - '0');
	(*format).width = value;
	return (offset - 1);
}
