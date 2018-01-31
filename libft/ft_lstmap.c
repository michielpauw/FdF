/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:43:15 by mpauw             #+#    #+#             */
/*   Updated: 2017/11/10 13:33:10 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*cur;

	if (lst)
	{
		if (!(map = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		lst = lst->next;
		cur = map;
	}
	else
		return (NULL);
	while (lst)
	{
		if (!(cur->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		cur = cur->next;
		lst = lst->next;
	}
	return (map);
}
