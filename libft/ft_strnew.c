/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:38:50 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/08 12:23:59 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*to_return;

	if (!(to_return = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size + 1)
	{
		size--;
		*(to_return + size + 1) = 0;
	}
	return (to_return);
}
