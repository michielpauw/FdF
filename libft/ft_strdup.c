/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:06:41 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/07 17:54:58 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	int		i;
	char	*to_return;

	length = ft_strlen(s1);
	i = 0;
	if (!(to_return = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (*(s1 + i))
	{
		*(to_return + i) = *(s1 + i);
		i++;
	}
	*(to_return + i) = 0;
	return (to_return);
}
