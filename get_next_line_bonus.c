/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:49:06 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/02 12:00:45 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(char *remainder, int fd)
{
	char	*reading;
	char	*temp;
	int		bytes;

	reading = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!reading)
		return (free(remainder), NULL);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(remainder, '\n'))
	{
		bytes = read(fd, reading, BUFFER_SIZE);
		if (bytes < 0)
			return (free(reading), free(remainder), NULL);
		reading[bytes] = '\0';
		temp = ft_strjoin(remainder, reading);
		free(remainder);
		if (!temp)
			return (free(reading), NULL);
		remainder = temp;
	}
	free (reading);
	return (remainder);
}

static char	*get_line(char *remainder)
{
	int		i;
	char	*str;

	if (!remainder || remainder[0] == '\0')
		return (NULL);
	i = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (remainder[i] == '\n')
		str = ft_substr(remainder, 0, i + 1);
	else
		str = ft_substr(remainder, 0, i);
	return (str);
}

static char	*update_remainder(char *remainder)
{
	char	*rest;
	int		i;
	int		len;

	len = ft_strlen(remainder);
	i = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (remainder[i] == '\0')
		return (free(remainder), NULL);
	rest = ft_substr(remainder, i + 1, len - i - 1);
	free(remainder);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	if (!remainder[fd])
	{
		remainder[fd] = ft_calloc(1, sizeof(char));
		if (!remainder[fd])
			return (NULL);
	}
	remainder[fd] = read_file(remainder[fd], fd);
	if (!remainder[fd])
		return (NULL);
	line = get_line(remainder[fd]);
	remainder[fd] = update_remainder(remainder[fd]);
	return (line);
}
