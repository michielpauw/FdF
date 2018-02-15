/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_3v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:26:35 by mpauw             #+#    #+#             */
/*   Updated: 2018/02/02 12:34:40 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate_3v(t_3v *v, int axis, double angle, int rad)
{
	double	e[3];

	if (!v)
		return ;
	if (!rad)
		angle = angle * RAD;
	e[0] = (v->v)[0];
	e[1] = (v->v)[1];
	e[2] = (v->v)[2];
	(v->v)[axis] = e[axis];
	(v->v)[(axis + 1) % 3] = cos(angle) * e[(axis + 1) % 3]
		- sin(angle) * e[(axis + 2) % 3];
	(v->v)[(axis + 2) % 3] = cos(angle) * e[(axis + 2) % 3]
		+ sin(angle) * e[(axis + 1) % 3];
}
