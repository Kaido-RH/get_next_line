/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrahmou <ahrahmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:37:36 by ahrahmou          #+#    #+#             */
/*   Updated: 2025/11/21 07:43:29 by ahrahmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_leftover(char **leftover, char *tmp, size_t len)
{
	tmp = ft_substr(*leftover, len, ft_strlen(*leftover) - len);
	free(*leftover);
	*leftover = (NULL);
	*leftover = tmp;
	if (!*leftover)
	{
		free(*leftover);
		return ;
	}
	if (**leftover == '\0')
	{
		free(*leftover);
		*leftover = NULL;
	}
	return ;
}

char	*new_line(char **leftover)
{
	char		*new_line;
	size_t		len;
	char		*line;

	if (!*leftover)
		return (NULL);
	new_line = ft_strchr(*leftover, '\n');
	if (new_line)
	{
		len = new_line - *leftover + 1;
		line = ft_substr(*leftover, 0, len);
		if (!line)
			return (free(*leftover), *leftover = NULL, NULL);
		free_leftover(leftover, line, len);
	}
	else
	{
		line = ft_strdup(*leftover);
		free(*leftover);
		*leftover = (NULL);
	}
	return (line);
}

char	*fill_leftover(int fd, ssize_t bytes, char *buf, char **leftover)
{
	char	*tmp;

	while (bytes > 0)
	{
		buf[bytes] = '\0';
		tmp = ft_strjoin(*leftover, buf);
		free(*leftover);
		*leftover = tmp;
		if (!*leftover)
			return (NULL);
		if (ft_strchr(*leftover, '\n'))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*leftover);
			*leftover = (NULL);
			return (NULL);
		}
	}
	return (*leftover);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes;
	char		*buf;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftover && ft_strchr(leftover, '\n'))
		return (new_line(&leftover));
	buf = malloc(BUFFER_SIZE +1);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == -1)
	{
		free(buf);
		free(leftover);
		leftover = (NULL);
		return (NULL);
	}
	leftover = fill_leftover(fd, bytes, buf, &leftover);
	free (buf);
	return (new_line(&leftover));
}
