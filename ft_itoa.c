/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:00:26 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/19 13:55:12 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_size(int n)
{
	int				i;
	unsigned int	pos_n;

	i = 1;
	pos_n = n;
	if (n < 0)
		pos_n *= -1;
	while (pos_n >= 10)
	{
		i++;
		pos_n /= 10;
	}
	return (i);
}

static int	neg_num(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*zero(char *str)
{
	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	pos_n;

	i = num_size(n) - 1 + neg_num(n);
	pos_n = n;
	str = malloc((num_size(n) * sizeof(char)) + neg_num(n) + 1);
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	if (neg_num(n))
		str[0] = '-';
	if (n < 0)
		pos_n *= -1;
	while (pos_n > 0)
	{
		str[i--] = (pos_n % 10) + '0';
		pos_n /= 10;
	}
	if (n == 0)
	{
		free(str);
		return (zero(str));
	}
	return (str);
}
