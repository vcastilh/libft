/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:15:25 by vcastilh          #+#    #+#             */
/*   Updated: 2022/03/17 14:58:14 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(char *name, char **envp)
{
	if ((name == NULL) | (envp == NULL))
		return (NULL);
	while (envp)
	{
		if (!ft_strncmp(name, *envp, ft_strlen(name)))
		{
			*envp += ft_strlen(name);
			return (*envp + 1);
		}
		else
			envp++;
	}
	return (NULL);
}
