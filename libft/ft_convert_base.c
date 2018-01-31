/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:39:14 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/13 11:02:00 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_dec(const char *nbr, const char *base_from)
{
	int len_from;
	int len_nbr;
	int	dec;
	int	sign;
	int	i;

	len_from = ft_strlen(base_from);
	len_nbr = ft_strlen(nbr);
	sign = *nbr == '-' ? -1 : 1;
	dec = 0;
	while (len_nbr--)
	{
		i = 0;
		if (*nbr != '-')
		{
			while (*(base_from + i) != *nbr)
				i++;
			dec = dec + i * ft_power(len_from, len_nbr);
		}
		nbr++;
	}
	return (sign * dec);
}

static char	*get_new(int nbr, const char *base_to)
{
	char	*conv;
	size_t	len_new;
	size_t	len_to;
	int		sign;
	int		i;

	len_to = ft_strlen(base_to);
	sign = nbr < 0 ? -1 : 1;
	i = nbr < 0 ? 1 : 0;
	len_new = 1;
	while (ft_power(len_to, len_new) < (size_t)nbr * sign)
		len_new++;
	if (!(conv = (char *)malloc(sizeof(char) * (len_new + 1 + i))))
		return (NULL);
	if (sign < 0)
		*conv = '-';
	while (len_new)
	{
		*(conv + i) = *(base_to + ((sign * nbr % ft_power(len_to, len_new)) /
				ft_power(len_to, len_new - 1)));
		i++;
		len_new--;
	}
	*(conv + i) = 0;
	return (conv);
}

char		*ft_convert_base(const char *nbr, const char *base_from,
		const char *base_to)
{
	int	dec;

	dec = get_dec(nbr, base_from);
	return (get_new(dec, base_to));
}
