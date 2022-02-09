/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:27:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 10:36:14 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

// bit mask : [ err + sp # * .* 0 - ]

int	is_valid_format(t_format format)
{
	if (format.specifier == 'c' || format.specifier == 'p')
		return (!(format.flags.byte & 0b11110110));
	else if (format.specifier == 's')
		return (!(format.flags.byte & 0b11110010));
	else if (format.specifier == 'd' || format.specifier == 'i')
		return (!(format.flags.byte & 0b10010000));
	else if (format.specifier == 'u')
		return (!(format.flags.byte & 0b11110000));
	else if (format.specifier == 'x' || format.specifier == 'X')
		return (!(format.flags.byte & 0b11100000));
	else
		return (!(format.flags.byte & 0b10000000));
}
