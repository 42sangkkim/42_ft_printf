/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:09:06 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/05 15:27:45 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	putc(t_format format, int c)
{
	char	buffer[2];

	buffer[0] = c;
	buffer[1] = '\0';
	puts(format, buffer);
}
