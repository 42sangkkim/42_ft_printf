/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_precision_reverse_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:30:24 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/08 20:58:30 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	match_precision_reverse(char **buffer, int precision)
{
	int		offset;
	char	*old_buffer;
	char	*new_buffer;

	old_buffer = *buffer;
	new_buffer = calloc(precision + 3, sizeof(char));
	if (new_buffer)
	{
		copy_digits(new_buffer, old_buffer);
		memset(strchr(new_buffer, '\0'), '0', precision - stren(new_buffer));
		copy_prefix(new_buffer, old_buffer);
	}
	free(*buffer);
	*buffer = new_buffer;
}

void	copy_digits(char *new_buffer, char *old_buffer)
{
	while (strchr("0123456789abcdefABCDEF", *old_buffer))
		*new_buffer++ = *old_buffer++;
}

void	copy_prefix(char *new_buffer, char *old_buffer)
{
	new_buffer = strchr(new_buffer, '\0');
	while (strchr("0123456789abcdefABCDEF", *old_buffer))
		old_buffer++;
	while (!*old_buffer)
		*new_buffer++ = *old_buffer;
}
