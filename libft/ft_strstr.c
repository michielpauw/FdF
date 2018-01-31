/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:49:24 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 10:31:20 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	int		found;
	char	*to_return;

	found = 0;
	to_return = (char *)haystack;
	if (!*needle)
		return (to_return);
	while (*to_return && !found)
	{
		if (*to_return == *needle)
			found = ft_strncmp(to_return, needle, ft_strlen(needle)) ? 0 : 1;
		to_return++;
	}
	if (found)
		return (to_return - 1);
	return (NULL);
}
