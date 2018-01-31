/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:13:45 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/08 12:02:29 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*to_return;

	to_return = dst;
	while (*src && len)
	{
		*dst = *(src++);
		dst++;
		len--;
	}
	while (len)
	{
		*dst = 0;
		dst++;
		len--;
	}
	return (to_return);
}
