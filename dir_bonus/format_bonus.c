/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:52:04 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/06 12:35:28 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_valid(t_format format)
{
	if (format.specifier == 'c' || format.specifier == 'p')
		return (!(format.flags.byte & 0b00110111));
	if (format.specifier == 's')
		return (!(format.flags.byte & 0b00100111));
	if (format.specifier == 'd' || format.specifier == 'i')
		return (!(format.flags.byte & 0b00000100));
	if (format.specifier == 'x' || format.specifier == 'X')
		return (!(format.flags.byte & 0b00010000));
	else
		return (!(format.flags.byte & 0b00010010));
}
