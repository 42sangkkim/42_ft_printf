/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:50:08 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/10 12:21:06 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_flags(const char **f_string, t_format *format);
void	set_width(const char **f_string, t_format *format);
void	set_precision(const char **f_string, t_format *format);

t_format	get_format(const char **f_string)
{
	t_format	format;

	bzero(&format, sizeof(t_format));
	*f_string += 1;
	set_flags(f_string, &format);
	if (isdigit(**f_string))
		set_width(f_string, &format);
	if (**f_string == '.')
		set_precision(f_string, &format);
	format.specifier = **f_string;
	if (**f_string)
		*f_string += 1;
	return (format);
}

void	set_flags(const char **f_string, t_format *format)
{
	while (1)
	{
		if (**f_string == '-')
			format->flags.minus = 1;
		else if (**f_string == '0')
			format->flags.zero = 1;
		else if (**f_string == '#')
			format->flags.sharp = 1;
		else if (**f_string == ' ')
			format->flags.space = 1;
		else if (**f_string == '+')
			format->flags.plus = 1;
		else
			break ;
		*f_string += 1;
	}
}

void	set_width(const char **f_string, t_format *format)
{
	format->flags.width = 1;
	format->width = strtol(*f_string, NULL, 10);
	while (isdigit(**f_string))
		*f_string += 1;
}

void	set_precision(const char **f_string, t_format *format)
{
	format->flags.precision = 1;
	*f_string += 1;
	format->precisoin = strtol(*f_string, NULL, 10);
	while (isdigit(**f_string))
		*f_string += 1;
}
