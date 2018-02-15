/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:39:05 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/27 16:38:07 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buff	*get_buff(int fd)
{
	static t_list	*list = NULL;
	t_buff			*buff;
	t_list			*tmp;

	tmp = list;
	while (tmp && tmp->content)
	{
		buff = *(t_buff **)tmp->content;
		if (buff->fd == fd)
			return (buff);
		tmp = tmp->next;
	}
	if (!(buff = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	buff->fd = fd;
	if (!(list) && !(list = ft_lstnew(NULL, 0)))
		return (NULL);
	if (!(buff->buff = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (NULL);
	ft_lstaddnewr(&list, &buff, sizeof(buff));
	return (buff);
}

static int		write_to_line(t_buff *buff, char **line, size_t *to_alloc, size_t *read_so_far)
{
	size_t	len_line;
	char	cur_c;

	len_line = ft_strlen(*line);
	while (*read_so_far < BUFF_SIZE)
	{
		cur_c = buff->buff[*read_so_far];
		buff->buff[*read_so_far] = 0;
		(*read_so_far)++;
		if (!cur_c && (*read_so_far = BUFF_SIZE + 2))
			return (3);
		if (cur_c == '\n')
			return (1);
		if (len_line + 1 >= *to_alloc)
			ft_realloc((void **)line, *to_alloc + 1, (*to_alloc *= 2) + 1);
		*(*line + len_line++) = cur_c;
		*(*line + len_line) = 0;
	}
	return (2);
}

static int		read_file(t_buff *buff, char **line, size_t to_alloc, size_t *read_so_far)
{
	int	status;
	int	read_r;

	status = 0;
	while (status == 0 || status == 2)
	{
		if (status == 2 || *read_so_far >= BUFF_SIZE)
		{
			*read_so_far = 0;
			buff->buff = (char *)ft_memset(buff->buff, 0, BUFF_SIZE);
			if (0 >= ((read_r = read(buff->fd, buff->buff, BUFF_SIZE)))
					&& !(**line))
				return (read_r);
			else if (!read_r)
				return (1);
		}
		status = write_to_line(buff, line, &to_alloc, read_so_far);
	}
	if (status == 3)
		return ((**line) ? 1 : 0);
	return (status);
}

int				get_next_line(const int fd, char **line)
{
	t_buff	*buff;
	size_t	to_alloc;
	size_t	read_so_far;

	buff = get_buff(fd);
	to_alloc = BUFF_SIZE;
	if (!line || !(*line = ft_strnew(to_alloc + 1)) || !buff)
		return (-1);
	read_so_far = 0;
	while (!buff->buff[read_so_far] && read_so_far < BUFF_SIZE)
		read_so_far++;
	if (read_so_far == BUFF_SIZE + 2)
		return (0);
	return (read_file(buff, line, to_alloc, &read_so_far));	
}
