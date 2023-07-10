/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:57:26 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/05 17:59:00 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sublen(char const *str, unsigned int start, size_t len)
{
	size_t	res;

	res = 0;
	while (start < ft_strlen(str) && res < len)
	{
		res++;
		start++;
	}
	return (res);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * (sublen(str, start, len) + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(str) && j < len)
		res[j++] = str[i++];
	res[j] = 0;
	return (res);
}
