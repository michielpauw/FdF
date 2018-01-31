/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:37:12 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 12:03:00 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 1;
	i = 0;
	while (*(s + len) && *(s + len) != c)
		len++;
	if (!(word = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (i < len)
		*(word + i++) = *(s++);
	*(word + i) = 0;
	return (word);
}

static	int	get_amount(char const *s, char c)
{
	int	amount;

	amount = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			amount++;
			while (*s != c && *s)
				s++;
		}
	}
	return (amount);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**to_return;
	char	*word;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(to_return = (char **)malloc(sizeof(char *) *
					(get_amount(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word = get_word(s, c);
			*(to_return + i++) = word;
			while (*s != c && *s)
				s++;
		}
	}
	*(to_return + i) = 0;
	return (to_return);
}
