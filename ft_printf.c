/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:28:56 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 10:53:44 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_exit(va_list *ap, int return_value);
int	print_fstring(const char *f_string, va_list *ap);
int	skip_fstring(const char *f_string);

int	ft_printf(const char *f_string, ...)
{
	int		temp_len;
	int		total_len;
	va_list	ap;

	total_len = 0;
	va_start(ap, f_string);
	while (*f_string)
	{
		if (*f_string == '%')
			print_format(&f_string, &ap);
		else
			print_string(&f_string);
		if (temp_len < 0)
			break ;
		else
			total_len += temp_len;
	}
	va_end(ap);
	return (total_len);
}
