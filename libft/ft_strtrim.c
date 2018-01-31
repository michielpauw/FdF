/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:19:57 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 11:58:52 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(char const *s)
{
	int	length;

	length = 0;
	while (*(s + length))
		length++;
	length--;
	while (*(s + length) == ' ' || *(s + length) == '\n'
			|| *(s + length) == '\t')
		length--;
	if (length < 0)
		return (0);
	return (length + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*to_return;
	int		i;
	int		length;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	length = get_length(s);
	if (!(to_return = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	to_return = ft_strsub(s, 0, length);
	return (to_return);
}
