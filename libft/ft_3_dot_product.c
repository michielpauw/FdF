/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_dot_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:24:19 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/23 10:31:39 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_3_dot_product(t_3v *v1, t_3v *v2)
{
	double	dot_product;
	int		i;

	if (!v1 || !v2)
		return (0);
	dot_product = 0;
	i = 0;
	while (i < 3)
	{
		dot_product += (v1->v)[i] * (v2->v)[i];
		i++;
	}
	return (dot_product);
}
