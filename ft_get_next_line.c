/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:15:53 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/10 11:12:08 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char	**buffer_backup, char	*ptr_n)
{
	char	*tmp_free;
	char	*line_return;
	size_t	i;

	if (!ptr_n)
	{
		if (**buffer_backup == '\0')
		{
			free(*buffer_backup);
			*buffer_backup = NULL;
			return (NULL);
		}
		line_return = *buffer_backup;
		*buffer_backup = NULL;
		return (line_return);
	}
	tmp_free = *buffer_backup;
	i = ptr_n - tmp_free + 1;
	line_return = ft_substr(tmp_free, 0, i);
	*buffer_backup = ft_strdup(&tmp_free[i]);
	free(tmp_free);
	tmp_free = NULL;
	return (line_return);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	char	*ptr;

	ptr = (char *)s;
	s_len = ft_strlen(ptr) + 1;
	while (s_len--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char	*read_file(int fd, char	*buffer, char **buffer_backup)
{
	ssize_t	bytes_read;
	char	*tmp_free;

	while (!ft_strchr(*buffer_backup, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
		{
			return (get_line(buffer_backup, 0));
		}
		buffer[bytes_read] = '\0';
		tmp_free = *buffer_backup;
		*buffer_backup = ft_strjoin(tmp_free, buffer);
		free(tmp_free);
		tmp_free = NULL;
	}
	return (get_line(buffer_backup, ft_strchr(*buffer_backup, '\n')));
}

char	*ft_get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_backup[LIMIT_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > LIMIT_FD)
		return (NULL);
	if (!buffer_backup[fd])
		buffer_backup[fd] = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_file(fd, buffer, &buffer_backup[fd]);
	free(buffer);
	buffer = NULL;
	return (line);
}
