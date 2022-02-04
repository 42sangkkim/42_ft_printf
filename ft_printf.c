/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:28:56 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 12:40:16 by sangkkim         ###   ########.fr       */
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
		temp_len = print_fstring(f_string, &ap);
		if (temp_len < 0)
			return (ft_exit(&ap, -1));
		total_len += temp_len;
		f_string += skip_fstring(f_string);
	}
	return (ft_exit(&ap, total_len));
}

int	ft_exit(va_list *ap, int return_value)
{
	va_end(*ap);
	return (return_value);
}
