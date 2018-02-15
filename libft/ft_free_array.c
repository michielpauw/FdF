/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:55:11 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/04 17:01:11 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void **to_free)
{
	int	i;

	i = 0;
	while (*(to_free + i))
		free(*(to_free + i++));
	free(to_free);
}
