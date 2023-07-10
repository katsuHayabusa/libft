/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:41:41 by saichaou          #+#    #+#             */
/*   Updated: 2022/12/05 15:28:51 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	int			chr;

	nb = (long int) n;
	if (nb < 0)
	{
		nb = -nb;
		write (fd, "-", 1);
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
	else
	{
		chr = nb % 10;
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		ft_putchar_fd(chr + '0', fd);
	}
}
