/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:31:38 by sangkkim          #+#    #+#             */
/*   Updated: 2021/11/26 17:48:41 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mem;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	mem = ft_strdup(s);
	if (!mem)
		return (NULL);
	i = 0;
	while (*(mem + i))
	{
		*(mem + i) = f(i, *(mem + i));
		i++;
	}
	return (mem);
}
