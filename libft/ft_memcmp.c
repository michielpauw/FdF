/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:47:17 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/09 15:39:48 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && n - 1)
	{
		s1++;
		s2++;
		n--;
	}
	if (*(unsigned char *)s1 != *(unsigned char *)s2 && n)
		return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
	return (0);
}
