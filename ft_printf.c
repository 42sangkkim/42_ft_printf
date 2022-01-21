/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:27:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/01/21 19:38:37 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int		print_format(char format, unsigned long arg);
char	*ft_strchr(const char *s, int c);

int	ft_printf(const char *f_string, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, f_string);
	while (*f_string)
	{
		if (*f_string == '%')
		{
			f_string += 1;
			if (*f_string == '%')
				len += write(1, f_string, 1);
			else if (ft_strchr("cspdiuxX", *f_string))
				len += print_format(*f_string, va_arg(ap, unsigned long));
			else
				return (-1);
			f_string += 1;
		}
		else
			len += write(1, f_string++, 1);
	}
	return (len);
}
