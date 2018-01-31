/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:12:59 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/09 15:31:41 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_return;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	if (!(to_return = (char *)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		*(to_return + i++) = *(s1++);
	while (*s2)
		*(to_return + i++) = *(s2++);
	*(to_return + i) = 0;
	return (to_return);
}
