/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:25:24 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 10:40:41 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	put_format(t_format format, va_list *ap)
{
	if (format.specifier == 'c')
		put_char(format, va_arg(*ap, int));
	else if (format.specifier == 's')
		put_str(format, va_arg(*ap, char *));
	else if (format.specifier == 'p')
		put_addr(format, va_arg(*ap, void *));
	else if (format.specifier == 'd' || format.specifier == 'i')
		put_deci(format, va_arg(*ap, int));
	else if (format.specifier == 'u')
		put_deci(format, va_arg(*ap, unsigned int));
	else if (format.specifier == 'x' || format.specifier == 'X')
		put_hex(format, va_arg(*ap, unsigned int));
	else
		put_default(format);
}
