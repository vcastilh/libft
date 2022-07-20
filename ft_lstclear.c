/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:55:52 by coder             #+#    #+#             */
/*   Updated: 2022/07/20 03:14:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst != NULL && del)
	{
		while (*lst != NULL)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(tmp, (*del));
		}
		lst = NULL;
	}
}
