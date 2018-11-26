/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:47:22 by mpauw             #+#    #+#             */
/*   Updated: 2018/11/26 11:10:16 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*add_point(t_point *lst, int x_val, int y_val, int z_val)
{
	t_point	*next;
	t_point	*tmp;

	if (!(next = (t_point *)malloc(sizeof(t_point))))
		error(1);
	next->x = (float)x_val * INIT_LINE * COMP_Z;
	next->y = (float)y_val * INIT_LINE * COMP_Z;
	next->z = (float)z_val * INIT_LINE;
	next->init_z = (float)z_val;
	next->next = NULL;
	next->b_v = 0xff;
	next->r_v = z_val * COL_DEPTH % 0xff;
	next->g_v = 0;
	if (lst == NULL)
		return (next);
	tmp = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = next;
	return (tmp);
}

static t_point	*point_to_pixel(t_point *lst, int width, int height)
{
	t_point	*tmp;
	int		sub_x;
	int		sub_y;

	sub_x = width * INIT_LINE * COMP_Z / 2;
	sub_y = height * INIT_LINE * COMP_Z / 2;
	tmp = lst;
	while (lst)
	{
		lst->x = lst->x - sub_x;
		lst->y = lst->y - sub_y;
		lst = lst->next;
	}
	return (tmp);
}

static void		double_free(char **values)
{
	int	i;

	i = 0;
	while (*(values + i))
		free(*(values + i++));
	free(values);
}

static t_point	*get_point_list(int fd, int *width, int *height)
{
	char	*line;
	char	**values;
	t_point	*lst;

	lst = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		*width = 0;
		values = ft_strsplit((const char *)line, ' ');
		while (*(values + *width))
		{
			lst = add_point(lst, *width, *height,
					ft_atoi(*(const char **)(values + *width)));
			(*width)++;
		}
		(*height)++;
		free(line);
		double_free(values);
	}
	free(line);
	return (lst);
}

t_point			*handle_file(char *file, int *width, int *height)
{
	t_point	*data;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error(errno);
	*width = 0;
	*height = 0;
	data = get_point_list(fd, width, height);
	data = point_to_pixel(data, *width, *height);
	if (*width == 0)
		error(errno);
	if (close(fd) != 0)
		error(errno);
	return (data);
}
