/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:36:13 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/11 19:23:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*match_precision_decimal(char *buffer, int precision)
{
	char	*new_buffer;
	int		offset;

	new_buffer = calloc(precision + 2, sizeof(char));
	if (new_buffer)
	{
		memset(new_buffer, '0', precision);
		offset = precision - digitlen(buffer);
		if (strchr("- +", *buffer))
		{
			*new_buffer = *buffer;
			strcpy(new_buffer + offset + 1, buffer + 1);
		}
		else
		{
			strcpy(new_buffer + offset, buffer);
		}
	}
	free(buffer);
	return (new_buffer);
}

char	*match_width_decimal(char *buffer, int width, t_flags flags)
{
	char	*new_buffer;

	new_buffer = calloc(width + 1, sizeof(char));
	if (new_buffer)
	{
		if (flags.minus)
			new_buffer = width_left_align(buffer, width);
		else if (!flags.precision && flags.zero)
			new_buffer = width_zero(buffer, width);
		else
			new_buffer = width_right_align(buffer, width);
	}
	free(buffer);
	return (new_buffer);
}

char	*width_left_align(char *buffer, int width)
{
	char	*new_buffer;

	new_buffer = calloc(width + 1, sizeof(char));
	if (new_buffer)
	{
		memset(new_buffer, ' ', width);
		memcpy(new_buffer, buffer, strlen(buffer));
	}
	return (new_buffer);
}

char	*width_zero(char *buffer, int width)
{
	char	*new_buffer;

	new_buffer = calloc(width + 1, sizeof(char));
	if (new_buffer)
	{
		memset(new_buffer, '0', width);
		if (strchr("- +", *buffer))
		{
			*new_buffer = *buffer;
			memcpy(new_buffer + width - strlen(buffer) + 1,
				buffer + 1, strlen(buffer + 1));
		}
		else
		{
			memcpy(new_buffer + width - strlen(buffer), buffer, strlen(buffer));
		}
	}
	return (new_buffer);
}

char	*width_right_align(char *buffer, int width)
{
	char	*new_buffer;

	new_buffer = calloc(width + 1, sizeof(char));
	if (new_buffer)
	{
		memset(new_buffer, ' ', width);
		memcpy(new_buffer + width - strlen(buffer), buffer, strlen(buffer));
	}
	return (new_buffer);
}
