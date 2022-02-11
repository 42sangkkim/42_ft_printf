/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:30:03 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 13:24:14 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// for demo version
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <inttypes.h>

typedef union u_flags
{
	unsigned char	byte;
	struct
	{
		unsigned char	minus : 1;
		unsigned char	zero : 1;
		unsigned char	precision : 1;
		unsigned char	width : 1;
		unsigned char	sharp : 1;
		unsigned char	space : 1;
		unsigned char	plus : 1;
	};
}	t_flags;

typedef struct s_format
{
	t_flags	flags;
	long	precision;
	long	width;
	char	specifier;
}	t_format;

int	ft_printf(const char *f_string, ...);

#endif