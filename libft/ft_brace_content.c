/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brace_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:50:11 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/30 17:31:44 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_string(char *input, int begin, int end)
{
	char	*content;
	int		i;

	if (!end || begin < 0)
		return (NULL);
	if (!(content = (char *)malloc(sizeof(char) * (end - begin))))
		return (NULL);
	i = 0;
	while (i < end - begin - 1)
	{
		*(content + i) = *(input + begin + i + 1);
		i++;
	}
	*(content + i) = 0;
	return (content);
}

char		*ft_brace_content(char *input, char o, char c)
{
	int		i;
	int		begin;
	int		end;
	int		open;

	i = 0;
	open = 0;
	end = 0;
	begin = -1;
	while (*(input + i) != 0)
	{
		if (*(input + i) == o)
		{
			if (!open)
				begin = i;
			open++;
		}
		else if (*(input + i) == c)
			open--;
		if (begin >= 0 && open == 0)
			end = i;
		i++;
	}
	return (get_string(input, begin, end));
}
