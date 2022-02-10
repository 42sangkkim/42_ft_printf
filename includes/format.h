/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:42:33 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/09 20:46:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

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
	long	precisoin;
	long	width;
	char	specifier;
}	t_format;

#endif