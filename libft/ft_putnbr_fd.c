/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:18:46 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 13:43:48 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		recur(int nb, int fd)
{
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
		return (0);
	}
	else
	{
		recur(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
		return (0);
	}
	return (0);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n = -n;
	}
	recur(n, fd);
}
