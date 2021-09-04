/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:31:38 by vcastilh          #+#    #+#             */
/*   Updated: 2021/09/04 00:12:22 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (unsigned char *)b1;
	p2 = (unsigned char *)b2;
	if (len != 0)
	{	
		while (len--)
		{
			if (*p1 == *p2)
			{
				p1++;
				p2++;
			}
			else
				return (*p1 - *p2);
		}
	}
	return (0);
}
