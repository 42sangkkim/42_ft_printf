/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:41:11 by sangkkim          #+#    #+#             */
/*   Updated: 2021/11/25 17:31:45 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	total_len;

	total_len = 0;
	while (*src && total_len + 1 < dstsize)
	{
		*dst++ = *src++;
		total_len++;
	}
	if (dstsize)
		*dst = 0;
	while (*src)
	{
		src++;
		total_len++;
	}
	return (total_len);
}
