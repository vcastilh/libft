/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:00:40 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/19 09:43:16 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_check_sign(const char *nptr)
{
	long double	sign;

	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	return (sign);
}

long double	ft_atold(const char *nptr)
{
	long double	res;
	long double	decimal;
	long double	sign;

	res = 0;
	decimal = 0.1;
	sign = ft_check_sign(nptr);
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	while (ft_isdigit(*nptr))
	{
		res = (res * 10) + *nptr - '0';
		nptr++;
	}
	if (*nptr++ == '.')
	{
		while (ft_isdigit(*nptr))
		{
			res += (*nptr++ - '0') * decimal;
			decimal *= 0.1;
		}
	}
	return (sign * res);
}
