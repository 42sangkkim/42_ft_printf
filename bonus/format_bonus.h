/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:38:57 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 01:02:42 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_BONUS_H
# define FORMAT_BONUS_H

typedef union u_flags
{
	unsigned char	byte;
	struct
	{
		unsigned char	minus : 1;
		unsigned char	zero : 1;
		unsigned char	precision : 1;
		unsigned char	width : 1;
		unsigned char	hash : 1;
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

#endif