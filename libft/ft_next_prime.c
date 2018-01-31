/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:39:46 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 15:27:59 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_next_prime(int nb)
{
	int	i;
	int	prime;

	prime = 0;
	if (nb <= 2)
		return (2);
	while (prime == 0)
	{
		i = 2;
		prime = 1;
		while (i * i < nb && nb % i != 0 && i < 65535)
			i++;
		if (nb % i == 0)
		{
			prime = 0;
			nb++;
		}
	}
	return (nb);
}
