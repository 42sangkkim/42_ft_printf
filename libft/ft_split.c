/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:56:16 by sangkkim          #+#    #+#             */
/*   Updated: 2021/11/26 17:49:55 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count += 1;
		s += 1;
	}
	return (count);
}

static char	*copy_one(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = ft_strlen(s);
	if (ft_strchr(s, c))
		len = (size_t)(ft_strchr(s, c) - s);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	free_all(char **words)
{
	char	**ptr;

	ptr = words;
	while (*ptr)
		free(*(ptr++));
	free(words);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**words;

	if (!s)
		return (NULL);
	words = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	i = 0;
	while (words && *s)
	{
		if (*s == c)
			s++;
		else
		{
			*(words + i) = copy_one(s, c);
			if (*(words + i) == NULL)
			{
				free_all(words);
				return (NULL);
			}
			s += ft_strlen(*(words + i));
			i += 1;
		}
	}
	return (words);
}
