/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:10:57 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 13:43:47 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		recur(int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return (0);
	}
	else
	{
		recur(nb / 10);
		ft_putchar(nb % 10 + '0');
		return (0);
	}
	return (0);
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		n = -n;
	}
	recur(n);
}
