/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:07:28 by vcastilh          #+#    #+#             */
/*   Updated: 2021/09/04 09:58:17 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			s_len;
	unsigned int	i;

	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len && s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
