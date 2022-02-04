/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_deci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:30:19 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 11:20:34 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	make_deci(char *buffer, long value);

int	put_deci(long value)
{
	char	buffer[30];

	bzero(buffer, 30);
	make_deci(buffer, value);
	return (write(1, buffer, strlen(buffer)));
}
