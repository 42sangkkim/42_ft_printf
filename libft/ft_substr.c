/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:53:20 by sangkkim          #+#    #+#             */
/*   Updated: 2021/11/26 17:42:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (!s)
		return (NULL);
	while (start--)
	{
		if (!*s)
			return (ft_strdup(s));
		s++;
	}
	if (ft_strlen(s) < len)
	{
		mem = ft_strdup(s);
	}
	else
	{
		mem = malloc(sizeof(char) * (len + 1));
		if (mem)
			ft_strlcpy(mem, s, len + 1);
	}
	return (mem);
}
