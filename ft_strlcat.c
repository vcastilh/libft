/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:53:32 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/21 04:57:20 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	total = dst_len + src_len;
	if (! (dstsize))
		return (src_len);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	while (dst_len < dstsize - 1 && *src)
	{
		dst[dst_len++] = *src;
		src++;
	}
	dst[dst_len] = '\0';
	if (dst_len < total)
		return (total);
	return (dst_len);
}
