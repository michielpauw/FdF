/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_3_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:14:00 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/23 12:20:08 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_3v	*ft_get_3_unit(int dir)
{
	t_3v	*vector;
	int		i;

	if (dir < 0 || dir > 2)
		return (NULL);
	if (!(vector = (t_3v *)malloc(sizeof(t_3v))))
		return (NULL);
	i = 0;
	while (i < 3)
	{
		if (i == dir)
			(vector->v)[i] = 1.0;
		else
			(vector->v)[i] = 0;
		i++;
	}
	return (vector);
}
