/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:50:08 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/10 12:19:31 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_format	get_format(const char **f_string)
{
	t_format	format;

	bzero(&format, sizeof(t_format));
	*f_string += 1;
	format.specifier = **f_string;
	if (**f_string)
		*f_string += 1;
	return (format);
}
