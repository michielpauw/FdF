/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 09:52:49 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/03 10:37:28 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

double	ft_atod(const char *s)
{
	int		before_dot;
	int		after_dot;
	double	to_return;

	before_dot = ft_atoi(s);
	while (!ft_isdigit((int)(*s)))
		s++;
	while (ft_isdigit((int)(*s)))
		s++;
	if (*s != '.')
	{
		return ((double)before_dot);
	}
	s++;
	after_dot = ft_atoi(s);
	to_return = (double)before_dot + ((double)after_dot /
			(double)ft_power(10, ft_numlen(after_dot)));
	return (to_return);
}
