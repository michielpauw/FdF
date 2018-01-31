/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:40:22 by mpauw             #+#    #+#             */
/*   Updated: 2017/12/08 17:00:20 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_img	*init_image(void *mlx, int width_scr, int height_scr)
{
	t_img	*img;
	int		bpp;
	int		size_line;
	int		endian;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	img->img_ptr = mlx_new_image(mlx, width_scr, height_scr);
	img->width = width_scr;
	img->height = height_scr;
	img->img_arr = mlx_get_data_addr(img->img_ptr, &bpp, &size_line, &endian);
	img->bpp = bpp;
	img->size_line = size_line;
	img->size_line_int = size_line / (bpp / 8);
	img->endian = endian;
	return (img);
}

static void		*get_rotate(void *mlx, void *win, t_img *img, t_point *points)
{
	t_rot	*rot;

	if (!(rot = (t_rot *)malloc(sizeof(t_rot))))
		return (NULL);
	rot->mlx = mlx;
	rot->win = win;
	rot->img = img;
	rot->points = points;
	rot->cam = 1;
	return (rot);
}

static t_rot	*movement(int key, t_rot *rot)
{
	if (key == 13)
		rot->points = simple_rotation(rot->points, 0, 1);
	else if (key == 1)
		rot->points = simple_rotation(rot->points, 0, -1);
	else if (key == 123)
		rot->points = simple_rotation(rot->points, 1, 1);
	else if (key == 124)
		rot->points = simple_rotation(rot->points, 1, -1);
	else if (key == 0)
		rot->points = simple_rotation(rot->points, 2, -1);
	else if (key == 2)
		rot->points = simple_rotation(rot->points, 2, 1);
	else if (key == 126)
		rot->cam -= CAM_STEP;
	else if (key == 125)
		rot->cam += CAM_STEP;
	return (rot);
}

static int		key_pressed(int key, void *ptr)
{
	t_rot	*rot;
	t_img	*new_img;

	rot = (t_rot *)ptr;
	if (key == 53)
		exit(0);
	else if ((key >= 123 && key <= 126) || (key >= 0 && key <= 2) || key == 13)
		rot = movement(key, rot);
	else if (key == 33)
		rot->points = change_color(rot->points, 1, 0);
	else if (key == 30)
		rot->points = change_color(rot->points, -1, 0);
	else if (key == 39)
		rot->points = change_color(rot->points, 1, 1);
	else if (key == 41)
		rot->points = change_color(rot->points, -1, 1);
	new_img = init_image(rot->mlx, IMG_W, IMG_H);
	rot->img = fill_image(rot->points, rot->width_p, new_img, rot->cam);
	mlx_put_image_to_window(rot->mlx, rot->win,
			(rot->img)->img_ptr, IMG_X, IMG_Y);
	free(new_img);
	return (1);
}

void			initialize(t_point *points, int width_p)
{
	void	*mlx;
	void	*win;
	t_img	*img;
	void	*rot;

	mlx = mlx_init();
	win = mlx_new_window(mlx, INIT_W, INIT_H, "Pink Floyd FdF");
	img = init_image(mlx, IMG_W, IMG_H);
	img = fill_image(points, width_p, img, 1);
	mlx_put_image_to_window(mlx, win, img->img_ptr, IMG_X, IMG_Y);
	rot = get_rotate(mlx, win, img, points);
	((t_rot *)rot)->width_p = width_p;
	((t_rot *)rot)->cam = 0;
	mlx_key_hook(win, &key_pressed, rot);
	mlx_loop(mlx);
	free(((t_rot *)rot)->img);
	free(((t_rot *)rot)->points);
	free(rot);
	free(img);
	free(points);
}
