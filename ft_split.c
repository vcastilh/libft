/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:09:11 by vcastilh          #+#    #+#             */
/*   Updated: 2021/09/04 09:26:23 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			n++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
	}
	return (n);
}

static char	**ft_get_words(char const *s, char c, size_t n_words, char **arr)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (n_words--)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i] != '\0')
			i++;
		arr[j] = (char *)malloc((i + 1) * sizeof(char));
		if (!*arr)
			return (NULL);
		i = 0;
		while (*s != c && *s)
			arr[j][i++] = *s++;
		arr[j][i] = '\0';
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**arr;

	n_words = ft_count_words(s, c);
	arr = (char **)malloc((n_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_get_words(s, c, n_words, arr);
	return (arr);
}
