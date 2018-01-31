/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:31:52 by mpauw             #+#    #+#             */
/*   Updated: 2017/12/06 12:17:00 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int code)
{
	strerror(code);
	exit(1);
}

int		main(int argc, char **argv)
{
	int		width;
	int		height;
	t_point	*points;

	if (argc != 2)
		return (1);
	points = handle_file(argv[1], &width, &height);
	initialize(points, width);
}
