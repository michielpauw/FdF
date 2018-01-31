/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:01:16 by mpauw             #+#    #+#             */
/*   Updated: 2017/12/11 10:31:42 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			get_index(t_point *data, int size_line_int, int cam)
{
	int		x_pix;
	int		y_pix;
	int		x_rel;
	t_point	*proj;

	proj = get_projection(data, cam);
	y_pix = round(proj->y);
	x_pix = round(proj->x);
	x_rel = x_pix + IMG_W / 2;
	free(proj);
	if (x_rel < 0 || x_pix >= IMG_W / 2 || y_pix >= IMG_H / 2)
	{
		data->index = -1;
		return ;
	}
	data->index = y_pix * size_line_int + x_pix +
		IMG_H / 2 * size_line_int + IMG_W / 2;
}

static unsigned int	get_color(t_point *b, t_point *e, int index, int total)
{
	unsigned int	color;

	if (total == 0)
		total++;
	color = round(((total - index) * b->b_v + index * e->b_v) / total);
	color += 0xff * round(((total - index) * b->g_v + index * e->g_v) / total);
	color += 0xffff * round(((total - index) * b->r_v +
				index * e->r_v) / total);
	return (color);
}

static t_img		*draw_line(t_img *img, t_point *b, t_point *e)
{
	int		width_dif;
	int		height_dif;
	int		index_h;
	int		index_v;
	float	slope;

	width_dif = e->index % img->size_line_int - b->index % img->size_line_int;
	height_dif = e->index / (img->size_line_int)
		- b->index / (img->size_line_int);
	slope = (float)(height_dif + (SIGN(height_dif))) / (width_dif + 1);
	index_h = 0;
	index_v = 0;
	while (index_h <= abs(width_dif) && index_v <= abs(height_dif))
	{
		((int *)(img->img_arr))[b->index + (SIGN(width_dif)) * index_h +
			index_v * (SIGN(height_dif)) * img->size_line_int] =
			get_color(b, e, index_h + index_v,
					abs(width_dif) + abs(height_dif));
		if (floor(fabs((float)((index_h + 1) * slope))) - 1 <= index_v)
			index_h++;
		else
			index_v++;
	}
	return (img);
}

t_img				*fill_image(t_point *dt, int width, t_img *img, int cam)
{
	t_point	**prev_l;
	int		i;

	i = -1;
	if (!(prev_l = (t_point **)malloc(width * sizeof(t_point *))))
		error(errno);
	while (dt->next)
	{
		get_index(dt, img->size_line_int, cam);
		if (dt->next)
		{
			get_index(dt->next, img->size_line_int, cam);
			if ((++i + 1) % width && dt->index > -1 && (dt->next)->index > -1)
				img = draw_line(img, dt, dt->next);
		}
		if (i >= width && dt->index > -1 && (prev_l[i % width])->index > -1)
			img = draw_line(img, dt, prev_l[i % width]);
		prev_l[i % width] = dt;
		dt = dt->next;
	}
	get_index(dt, img->size_line_int, cam);
	if (++i >= width && dt->index > -1 && (prev_l[i % width])->index > -1)
		img = draw_line(img, dt, prev_l[i % width]);
	free(prev_l);
	return (img);
}
