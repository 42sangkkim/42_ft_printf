/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:24:42 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/10 12:16:35 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../includes/format.h"

#define INT_MAX 0x7FFFFFFF

int	valid_specifier(char specifier);
int	valid_flags(char specifier, t_flags flags);
int	valid_width_precision(long width, long precision);

int	check_format(t_format format)
{
	if (!valid_specifier(format.specifier))
		return (0);
	else if (!valid_flags(format.specifier, format.flags))
		return (0);
	else if (!valid_width_precision(format.width, format.precisoin))
		return (0);
	else
		return (1);
}

int	valid_specifier(char specifier)
{
	return (strchr("cspdiuxX%", specifier) > 0);
}

// [ + sp # * .* 0 - ]
int	valid_flags(char specifier, t_flags flags)
{
	if (flags.minus && flags.zero)
		return (0);
	else if (flags.space && flags.plus)
		return (0);
	if (specifier == 'c' || specifier == 'p')
		return (!(flags.byte & 0b1110110));
	else if (specifier == 's')
		return (!(flags.byte & 0b1110010));
	else if (specifier == 'd' || specifier == 'i')
		return (!(flags.byte & 0b0010000));
	else if (specifier == 'u')
		return (!(flags.byte & 0b1110000));
	else if (specifier == 'x' || specifier == 'x')
		return (!(flags.byte & 0b1100000));
	else
		return (1);
}

int	valid_width_precision(long width, long precision)
{
	if (width < 0 || width > INT_MAX)
		return (0);
	else if (precision < 0 || precision > INT_MAX)
		return (0);
	else
		return (1);
}
