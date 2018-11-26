/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddright.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpauw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:20:56 by mpauw             #+#    #+#             */
/*   Updated: 2018/01/11 11:34:24 by mpauw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddright(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (!tmp->content)
	{
		free(*alst);
		*alst = new;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
