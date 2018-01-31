/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:39:05 by mpauw             #+#    #+#             */
/*   Updated: 2017/12/04 08:30:46 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd_list	*get_buff(int fd, int *new_buff)
{
	static t_fd_list	*list = NULL;
	t_fd_list			*current;
	t_fd_list			*prev;

	*new_buff = 0;
	current = list;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		prev = current;
		current = current->next;
	}
	if (!(current = (t_fd_list *)malloc(sizeof(t_fd_list)))
			|| !(current->buff = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (NULL);
	if (prev)
		prev->next = current;
	else
		list = current;
	current->fd = fd;
	current->next = NULL;
	*new_buff = 1;
	return (current);
}

static void			reallocate_mem(char **str, int *prev_mem)
{
	char	*temp;
	int		i;

	i = 0;
	temp = *str;
	if (!(*str = (char *)malloc(sizeof(char) * (*prev_mem * 2 + 1))))
		return ;
	while (*(temp + i))
	{
		*(*str + i) = *(temp + i);
		i++;
	}
	*prev_mem *= 2;
	free(temp);
}

static int			fill_string(char **line, t_fd_list *cur_fd, int *to_alloc)
{
	int		len_line;

	len_line = ft_strlen(*line);
	while (cur_fd->rsf < BUFF_SIZE && cur_fd->rsf < cur_fd->read_r)
	{
		if ((cur_fd->buff)[cur_fd->rsf] == '\n')
		{
			*(*line + len_line) = 0;
			(cur_fd->buff)[cur_fd->rsf++] = 0;
			return (1);
		}
		if (len_line + 1 >= *to_alloc)
			reallocate_mem(line, to_alloc);
		if ((cur_fd->buff)[cur_fd->rsf])
		{
			*(*line + len_line) = (cur_fd->buff)[cur_fd->rsf];
			len_line++;
			*(*line + len_line) = 0;
			(cur_fd->buff)[cur_fd->rsf] = 0;
		}
		(cur_fd->rsf)++;
	}
	cur_fd->eof = (cur_fd->rsf == cur_fd->read_r
			&& cur_fd->read_r < BUFF_SIZE) ? 1 : 2;
	return (cur_fd->eof);
}

static int			read_file(char **line, t_fd_list *cur_fd,
		int to_alloc, int is_new_buff)
{
	int			fill_status;

	**line = 0;
	fill_status = 0;
	while (cur_fd && (fill_status == 0 || fill_status == 2))
	{
		if (fill_status == 2 || cur_fd->rsf == cur_fd->read_r)
		{
			is_new_buff = 0;
			cur_fd->rsf = 0;
			if (0 >= ((cur_fd->read_r =
							read(cur_fd->fd, cur_fd->buff, BUFF_SIZE)))
					&& !(**line))
				return (cur_fd->read_r);
			else if (!cur_fd->read_r)
				return (1);
		}
		fill_status = fill_string(line, cur_fd, &to_alloc);
	}
	return (fill_status);
}

int					get_next_line(const int fd, char **line)
{
	int			to_alloc;
	int			is_new_buff;
	int			to_return;
	t_fd_list	*cur_fd;

	cur_fd = get_buff(fd, &is_new_buff);
	to_alloc = BUFF_SIZE;
	if (!line || !(*line = (char *)malloc(sizeof(char) * to_alloc + 1))
			|| !cur_fd)
		return (-1);
	if (cur_fd->eof == 1)
		return (0);
	to_return = read_file(line, cur_fd, to_alloc, is_new_buff);
	return (to_return);
}
