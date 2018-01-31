/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:51:42 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/09 15:29:22 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*to_return;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if (!(to_return = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (*s)
		*(to_return + i++) = f(*(s++));
	*(to_return + i) = 0;
	return (to_return);
}
