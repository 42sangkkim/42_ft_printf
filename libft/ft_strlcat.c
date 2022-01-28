/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:47:46 by sangkkim          #+#    #+#             */
/*   Updated: 2021/11/25 17:31:32 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total_len;

	total_len = 0;
	while (*dst && total_len < dstsize)
	{
		dst++;
		total_len++;
	}
	while (*src && total_len + 1 < dstsize)
	{
		*dst++ = *src++;
		total_len++;
	}
	if (total_len < dstsize)
		*dst = 0;
	while (*src)
	{
		src++;
		total_len++;
	}
	return (total_len);
}
