/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fstring_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:30:22 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 13:53:03 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void		print_format(const char **f_string, va_list *ap);
int			is_valid(t_format format);

t_format	get_format(const char *f_string);

int			put_char(t_format format, char c);
int			put_str(t_format format, char *s);
int			put_addr(t_format format, void *ptr);
int			put_deci(t_format format, long value);
int			put_hex(t_format format, unsigned long value, char hex_case);
int			put_default(t_format format, char c);

int	print_fstring(const char *f_string, va_list *ap)
{
	if (*f_string == '%')
		return (print_format(f_string + 1, ap));
	else
		return (print_string(f_string));
}

void	print_format(const char **f_string, va_list *ap)
{
	t_format	format;

	*f_string += 1;
	if (!**f_string)
		return (0);
	format = get_format(f_string);
	if (!is_valid_format(format))
		return (0);
	put_format(format, ap);
}
