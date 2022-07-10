/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:34:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 17:04:12 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "format_bonus.h"

int	check_format_bonus(t_format format)
{
	if (!ft_strchr("cspdiuxX%", format.specifier))
		TODO: undefined specifier;
	if (format.f_zero && format.f_minus)
		format.f_zero = 0;
	if (format.f_zero && format.f_precision && ft_strchr("duixX", format.specifier))
		format.f_zero = 0;
	if (format.f_hash && ft_strchr("cdipsu", format.specifier))
		format.f_hash = 0;
}