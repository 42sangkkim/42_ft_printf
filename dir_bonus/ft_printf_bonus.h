/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:58:18 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 14:09:40 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../ft_printf.h"

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	precision;
	int	width;
	int	sharp;
	int	space;
	int	plus;
}	t_flags;

typedef struct s_format
{
	t_flags	flags;
	int		precision;
	int		width;
	char	specifier;
}	t_format;

#endif