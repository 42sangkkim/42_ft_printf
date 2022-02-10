/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:24:42 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/10 12:17:04 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../includes/format.h"

#define INT_MAX 0x7FFFFFFF

int	valid_specifier(char specifier);

int	check_format(t_format format)
{
	if (!valid_specifier(format.specifier))
		return (0);
	else
		return (1);
}

int	valid_specifier(char specifier)
{
	return (strchr("cspdiuxX%", specifier) > 0);
}
