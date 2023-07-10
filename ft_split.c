/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:54:40 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/14 19:16:32 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wcount(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] && s[j] != c)
		{
			i++;
			while (s[j] && s[j] != c)
			{
				j++;
			}
		}
		while (s[j] && s[j] == c)
			j++;
	}
	return (i);
}

static size_t	charcount(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*char_split(char const *s, int len)
{
	char	*str;

	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = s[len];
	return (str);
}

static char	**free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		len;
	int		words;

	if (!s)
		return (NULL);
	split = malloc((wcount(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	len = 0;
	words = wcount(s, c);
	while (++i < words)
	{
		while (*s && *s == c)
			s++;
		len = charcount(s, c);
		split[i] = char_split(s, len);
		if (!split[i])
			return (free_all(split));
		s += len + 1;
	}
	split[words] = 0;
	return (split);
}
