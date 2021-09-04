/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 08:18:03 by vcastilh          #+#    #+#             */
/*   Updated: 2021/09/01 09:36:10 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end_sub;

	while (*s1 && ft_strchr(set,*s1))
	{
		s1++;
	}
	end_sub = ft_strlen(s1);
	while (end_sub && ft_strchr(set, s1[end_sub]))
	{
		end_sub--;
	}
	return (ft_substr(s1, 0, end_sub + 1));
}
