/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:05:54 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/09 11:59:30 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	**get_zero_matrix(size_t size)
{
	float	**zero_matrix;
	size_t	i;
	size_t	j;

	if (!(zero_matrix = (float **)malloc(size * sizeof(float *))))
		error(errno);
	i = 0;
	while (i < size)
	{
		if (!(zero_matrix[i] = (float *)malloc(size * sizeof(float))))
			error(errno);
		j = 0;
		while (j < size)
			zero_matrix[i][j++] = 0;
		i++;
	}
	return (zero_matrix);
}

float			**get_rotation_matrix(int axis, int dir)
{
	float	**rotation_matrix;

	rotation_matrix = get_zero_matrix(3);
	rotation_matrix[axis][axis] = 1;
	rotation_matrix[(axis + 1) % 3][(axis + 1) % 3] = cos(ROT_ANGLE * dir);
	rotation_matrix[(axis + 2) % 3][(axis + 2) % 3] = cos(ROT_ANGLE * dir);
	rotation_matrix[(axis + 1) % 3][(axis + 2) % 3] = -sin(ROT_ANGLE * dir);
	rotation_matrix[(axis + 2) % 3][(axis + 1) % 3] = sin(ROT_ANGLE * dir);
	return (rotation_matrix);
}
