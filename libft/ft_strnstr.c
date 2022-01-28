/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:55:23 by sangkkim          #+#    #+#             */
/*   Updated: 2021/11/29 20:37:19 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (*(needle + i))
		{
			if (i >= len)
				return (NULL);
			if (*(needle + i) != *(haystack + i))
				break ;
			i++;
		}
		if (!*(needle + i))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
