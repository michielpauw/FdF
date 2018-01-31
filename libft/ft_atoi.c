/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:10:45 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/08 16:32:05 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int to_return;
	int negative;

	i = 0;
	to_return = 0;
	negative = 1;
	while (*(str + i) == '\t' || *(str + i) == ' ' || *(str + i) == '\v'
			|| *(str + i) == '\n' || *(str + i) == '\f' || *(str + i) == '\r')
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			negative = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		to_return = to_return * 10 + (int)*(str + i) - 48;
		i++;
	}
	to_return = negative * to_return;
	return (to_return);
}
