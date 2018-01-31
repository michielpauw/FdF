/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:48:18 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/08 16:20:50 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned long	dst_add;
	unsigned long	src_add;

	i = 0;
	dst_add = (unsigned long)dst;
	src_add = (unsigned long)src;
	if (dst_add > src_add)
	{
		while (i < len)
		{
			i++;
			*(char *)(dst + len - i) = *(char *)(src + len - i);
		}
	}
	else
	{
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
