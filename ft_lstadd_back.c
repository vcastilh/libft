/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:31:50 by coder             #+#    #+#             */
/*   Updated: 2022/07/18 19:44:55 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last_node;

	if (lst && new_node)
	{
		if (*lst)
		{
			last_node = ft_lstlast(*lst); 
			last_node->next = new_node;
		}
		else
			*lst = new_node;
	}
}
