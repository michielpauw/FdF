/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:07:47 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/09 15:31:17 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*to_return;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(to_return = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len && *(s + start + i))
	{
		*(to_return + i) = *(s + start + i);
		i++;
		len--;
	}
	*(to_return + i) = 0;
	return (to_return);
}
