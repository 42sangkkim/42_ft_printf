/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:18:40 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/06 19:23:07 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_buf(int mode, char *buf)
{
	static int	printed;

	if (mode == 0)
		printed = 0;
	else if (mode == 1 && buf)
		printed += (write(1, buf, strlen(buf)));
	return (printed);
}
