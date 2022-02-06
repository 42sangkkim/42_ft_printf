/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putp_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:48:16 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/06 15:31:00 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// make_digit_bonus.c
void	make_addr(char *buf, unsigned long value);

// puts_bonus.c
void	puts(t_format format, const char *s);

void	putp(t_format format, void *p)
{
	char	buffer[20];

	bzero(buffer, 20);
	strcat(buffer, "0x");
	make_addr(buffer, (unsigned long)p);
	puts(format, buffer);
}
