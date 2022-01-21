/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:27:12 by sangkkim          #+#    #+#             */
/*   Updated: 2022/01/21 20:10:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len += 1;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char) c)
		s += 1;
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)0);
}
