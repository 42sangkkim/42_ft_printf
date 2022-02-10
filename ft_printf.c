/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:28:56 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 20:49:30 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "includes/format.h"

#include "ft_printf.h"

void	print_format(const char **f_string, va_list *ap);

int	ft_printf(const char *f_string, ...)
{
	char	*buffer;
	int		temp_len;
	int		print_len;
	va_list	ap;

	print_len = 0;
	va_start(ap, f_string);
	while (*f_string)
	{
		if (*f_string == '%')
			buffer = get_format_buffer(&f_string, &ap);
		else
			buffer = get_string_buffer(&f_string);
		if (!buffer)
			return (va_exit(&ap, -1));
		temp_len = write(1, buffer, strlen(buffer));
		free(buffer);
		if (temp_len < 0)
			return (va_exit(&ap, -1));
		print_len += temp_len;
	}
	va_exit(&ap, print_len);
}

char	*get_format_buffer(const char **f_string, va_list *ap)
{
	t_format	format;
	char		*buffer;

	format = get_format(f_string);
	if (!check_format(format))
		return (NULL);
	buffer = make_buffer(format, ap);
	return (buffer);
}

char	*get_stirng_buffer(const char **f_string)
{
	char	*start;
	char	*buffer;

	start = (char *)(*f_string);
	while (**f_string && **f_string != '%')
		*f_string += 1;
	buffer = strndup(start, *f_string - start);
	return (buffer);
}

int	va_exit(va_list *ap, int exit_code)
{
	va_end(*ap);
	return (exit_code);
}
