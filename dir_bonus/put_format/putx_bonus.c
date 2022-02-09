/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putx_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:15:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 10:18:31 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	putx(t_format format, unsigned long value)
{
	char	*buffer;

	if (format.specifier == 'x')
		build_hex_reverse(value, format.flags.sharp);
	else
		build_lhex_reverse(value, format.flags.sharp);
	if (buffer && format.flags.precision && format.precision > digitlen(buffer))
		buffer = match_precision_reverse(buffer, format.precision);
	if (buffer && format.flags.width && format.width > strlen(buffer))
		buffer = match_width_minus_reverse(buffer, format.width, format.flags);
	str_reverse(&buffer);
	// put_buffer(buffer);
	free(buffer);
}
