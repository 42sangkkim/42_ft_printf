/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:50:30 by sangkkim          #+#    #+#             */
/*   Updated: 2021/12/02 12:37:53 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	if (dst < src)
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	else if (dst > src)
	{
		while (len--)
			*(dst_ptr + len) = *(src_ptr + len);
	}
	return (dst);
}
