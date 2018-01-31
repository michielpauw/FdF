/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:17:48 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/09 11:54:20 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	dest_size = 0;
	src_size = 0;
	while (*(dst + dest_size))
		dest_size++;
	while (*(src + src_size))
		src_size++;
	if (!size)
		return (src_size);
	while (*(src + i) && ((dest_size + i) < size - 1))
	{
		*(dst + i + dest_size) = *(src + i);
		i++;
	}
	*(dst + i + dest_size) = 0;
	if (dest_size < size)
		return (src_size + dest_size);
	else
		return (src_size + size);
}
