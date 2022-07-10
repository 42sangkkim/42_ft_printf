/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:22:36 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 21:15:40 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "format_bonus.h"

int			calc_fill_len(char *buffer, t_format format);
void		init_prifix(char *prefix, t_format format, int is_minus);
int			calc_fill_len(char *buffer, t_format format);
int			print_buffer(t_padding padding, char *prefix, size_t fill_len, char *buffer);

const void	build_buffer(char *buffer, unsigned int value, size_t buf_size, char x);

// 0	: fill 0 padding
// .*	: min width of value
// *	: min width of output
// -	: right align with width
// +	: + a head of value
// sp	: sp a head of value
// #	: Undefined

int	put_x(unsigned int x, t_format format)
{
	char		buffer[9];
	int			fill_len;
	char		prefix[3];
	t_padding	padding;

	build_buffer(buffer, x, 9, format.specifier);
	fill_len = calc_fill_len(buffer, format);
	init_prefix(prefix, format, 0);
	init_padding(&padding, format,
		ft_strlen(prefix) + fill_len + ft_strlen(buffer));
	return (print_buffer(padding, prefix, fill_len, buffer));
}

const void	build_buffer(char *buffer, unsigned int value, size_t buf_size, char x)
{
	char	digit[2];

	if (value / 16)
		build_buffer(buffer, value / 16, buf_size, x);
	value %= 16;
	if (value >= 10)
		digit[0] = value - 10 + x;
	else
		digit[0] = value + '0';
	digit[1] = '\0';
	ft_strlcat(buffer, digit, buf_size);
}
