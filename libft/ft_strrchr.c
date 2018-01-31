/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:45:38 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/07 17:10:33 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = 0;
	while (*(s + length))
		length++;
	while (*(s + length) != c && length)
		length--;
	if (*(s + length) == c)
		return ((char *)(s + length));
	return (NULL);
}
