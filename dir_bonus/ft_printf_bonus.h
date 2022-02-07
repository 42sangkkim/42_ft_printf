/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:58:18 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/07 12:07:03 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../ft_printf.h"

typedef struct s_format
{
	union	u_flags
	{
		unsigned char	byte;
		struct {
			unsigned char	minus : 1;
			unsigned char	zero : 1;
			unsigned char	precision : 1;
			unsigned char	width : 1;
			unsigned char	sharp : 1;
			unsigned char	space : 1;
			unsigned char	plus : 1;
		};
	} flags;
	struct	s_precision
	{
		int		flag;
		long	value;
	}	precision;
	struct s_width
	{
		int		flag;
		long	value;
	}	width;
	char	specifier;
}	t_format;

#endif