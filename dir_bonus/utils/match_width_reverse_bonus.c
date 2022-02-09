/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_width_reverse_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:23:32 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/08 20:58:54 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*match_width_reverse(char *buffer, long width, t_flags flags)
{
	if (flags.minus)
		return (match_width_minus_reverse(buffer, width));
	else if (!flags.precision && flags.zero)
		return (match_width_zero_reverse(buffer, width));
	else
		return (match_width_normal_reverse(buffer, width));
}

char	*match_width_minus_reverse(char *buffer, long width)
{
	char	*new_buffer;

	new_buffer = calloc(width + 1, sizeof(char));
	if (new_buffer)
	{
		memset(new_buffer, ' ', width - strlen(buffer));
		strcat(new_buffer, buffer);
	}
	free(buffer);
	return (new_buffer);
}

char	*match_width_zero_reverse(char *buffer, long width)
{
	char	*new_buffer;

	new_buffer = calloc(width + 1, sizeof(char));
	if (new_buffer)
	{
		copy_digits(new_buffer, buffer);
		memset(strchr(new_buffer, '\0'), '0', width - strlen(buffer));
		copy_prefix(new_buffer, buffer);
	}
	free(buffer);
	return (new_buffer);
}

char	*match_width_normal_reverse(char *buffer, long width)
{
	char	*new_buffer;

	new_buffer = calloc(width + 1, sizeof(char));
	if (new_buffer)
	{
		strcpy(new_buffer, buffer);
		memset(strchr(new_buffer, '\0'), ' ', width - strlen(buffer));
	}
	free(buffer);
	return (new_buffer);
}
