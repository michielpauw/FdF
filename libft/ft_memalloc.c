/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:03 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/07 17:35:09 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*to_return;

	if (!(to_return = malloc(sizeof(char) * size)))
		return (NULL);
	while (size)
	{
		size--;
		*(char *)(to_return + size) = 0;
	}
	return (to_return);
}
