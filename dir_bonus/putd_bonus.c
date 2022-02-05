/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putd_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:27:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/05 15:31:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	putd(t_format format, int value)
{
	char	buffer[30];

	buffer = make_buffer(value, format.flags.plus, format.flags.space);
	if (buffer && format.flags.precision && format.precision > strlen(buffer))
		match_precision(&buffer, format.precision, format.flags.plus, format.flags.space);
}