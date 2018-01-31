/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:37:47 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/13 11:00:30 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*recur(int *fac, int nb, int i)
{
	int	prime;

	if (nb == 1)
	{
		*(fac + i) = 0;
		return (fac);
	}
	prime = 2;
	while (nb % prime)
	{
		prime = ft_next_prime(prime + 1);
	}
	*(fac + i) = prime;
	return (recur(fac, nb / prime, i + 1));
}

int			*ft_factorization(int nb)
{
	int	*fac;
	int	max;
	int	sign;

	sign = nb > 0 ? 1 : -1;
	max = 0;
	if (nb == 0)
	{
		sign = 0;
		fac = &sign;
		return (fac);
	}
	while (ft_power(2, max) < (size_t)(nb * sign))
		max++;
	if (!(fac = (int *)malloc(sizeof(int) * (max + 2))))
		return (NULL);
	*fac = sign;
	fac = recur(fac, nb * sign, 1);
	return (fac);
}
