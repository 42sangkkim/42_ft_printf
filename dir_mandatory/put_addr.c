/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_addr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:14:28 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 11:21:23 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	make_lowerhex(char *buffer, unsigned long value);

int	put_addr(void *ptr)
{
	unsigned long	addr;
	char			buffer[30];

	addr = (unsigned long)ptr;
	bzero(buffer, 30);
	buffer[0] = '0';
	buffer[1] = 'x';
	make_lowerhex(buffer + 2, addr);
	return (write(1, buffer, strlen(buffer)));
}
