/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 08:32:01 by mpauw             #+#    #+#             */
/*   Updated: 2017/12/07 13:12:06 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define RATIO 5 * 4
# define INIT_W 2000
# define INIT_H	1400
# define IMG_W 2 * INIT_W
# define IMG_H 2 * INIT_H
# define IMG_X -INIT_W / 2
# define IMG_Y -INIT_H / 2
# define INIT_LINE 10
# define COMP_Z 3
# define ROT_ANGLE M_PI / 8
# define DIST_CAM 3000
# define CAM_STEP 30
# define SIGN(x) (x < 0) ? -1 : 1
# define COL_DEPTH 10
# define COL_CHANGE 15
# define DEPTH_CHANGE 5

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>

typedef struct	s_point
{
	float			x;
	float			y;
	float			z;
	float			init_z;
	int				index;
	unsigned char	r_v;
	unsigned char	g_v;
	unsigned char	b_v;
	struct s_point	*next;
}				t_point;

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_arr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		size_line_int;
	int		endian;
}				t_img;

typedef struct	s_rot
{
	t_img	*img;
	t_point	*points;
	int		width_p;
	void	*win;
	void	*mlx;
	int		cam;
}				t_rot;

t_img			*fill_image(t_point *data, int width, t_img *img, int cam);
t_point			*handle_file(char *file, int *width, int *height);
void			initialize(t_point *points, int width);
t_point			*simple_rotation(t_point *points, int axis, int dir);
float			**get_rotation_matrix(int axis, int direction);
t_point			*get_projection(t_point *data, int cam);
t_point			*change_color(t_point *data, int dir, int z_change);
void			error(int code);

#endif
