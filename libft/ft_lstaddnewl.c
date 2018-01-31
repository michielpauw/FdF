/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnewl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:30:11 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 13:16:01 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstaddnewl(t_list **alst, void const *content, size_t content_size)
{
	t_list	*to_add;

	if ((to_add = ft_lstnew(content, content_size)))
	{
		ft_lstadd(alst, to_add);
		return (1);
	}
	return (0);
}
