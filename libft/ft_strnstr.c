/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:57:54 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 11:25:55 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	int		found;
	size_t	n_len;
	char	*to_return;

	found = 0;
	n_len = ft_strlen(needle);
	to_return = (char *)haystack;
	if (!*needle)
		return (to_return);
	while (*to_return && !found && len)
	{
		if (len < n_len && !found)
			return (NULL);
		if (*to_return == *needle)
			found = ft_strncmp(to_return, needle, n_len) ? 0 : 1;
		to_return++;
		len--;
	}
	if (found)
		return (to_return - 1);
	return (NULL);
}
