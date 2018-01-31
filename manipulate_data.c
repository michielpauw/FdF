/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:40:52 by mpauw             #+#    #+#             */
/*   Updated: 2017/12/07 13:12:07 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*matrix_mult_3d(t_point *p, float **mat)
{
	float	x_cur;
	float	y_cur;
	float	z_cur;

	x_cur = p->x;
	y_cur = p->y;
	z_cur = p->z;
	p->x = x_cur * mat[0][0] + y_cur * mat[0][1] + z_cur * mat[0][2];
	p->y = x_cur * mat[1][0] + y_cur * mat[1][1] + z_cur * mat[1][2];
	p->z = x_cur * mat[2][0] + y_cur * mat[2][1] + z_cur * mat[2][2];
	return (p);
}

t_point			*get_projection(t_point *data, int cam)
{
	t_point	*proj;

	if (!(proj = (t_point *)malloc(sizeof(t_point))))
		error(errno);
	proj->z = DIST_CAM + cam - data->z;
	if (round(proj->z) == 0)
		(proj->z)++;
	proj->x = (data->x * IMG_W) / proj->z;
	proj->y = (data->y * IMG_H) / proj->z;
	return (proj);
}

t_point			*simple_rotation(t_point *points, int axis, int dir)
{
	float	**rotation_matrix;
	t_point	*tmp;
	int		i;

	rotation_matrix = get_rotation_matrix(axis, dir);
	tmp = points;
	while (points)
	{
		points = matrix_mult_3d(points, rotation_matrix);
		points = points->next;
	}
	i = 0;
	while (i < 3)
		free(rotation_matrix[i++]);
	free(rotation_matrix);
	return (tmp);
}

t_point			*change_color(t_point *points, int dir, int z_change)
{
	t_point *tmp;
	float	z;

	tmp = points;
	while (points)
	{
		z = points->init_z;
		if (z_change && z)
		{
			points->r_v = (char)(points->r_v + dir * z * DEPTH_CHANGE) % 0xff;
			points->g_v = (char)(points->g_v + dir * z * DEPTH_CHANGE) % 0xff;
			points->b_v = (char)(points->b_v + dir * z * DEPTH_CHANGE) % 0xff;
		}
		else if (!z_change)
		{
			points->r_v = (points->r_v + dir * COL_CHANGE) % 0xff;
			points->g_v = (points->g_v + dir * COL_CHANGE) % 0xff;
			points->b_v = (points->b_v + dir * COL_CHANGE) % 0xff;
		}
		points = points->next;
	}
	return (tmp);
}
