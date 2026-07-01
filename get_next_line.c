/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:37:12 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/01 17:09:10 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(char *remainder, int fd)
{
	char	*reading;
	char	*temp;
	int		bytes;

	bytes = 1;
	reading = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!reading)
	{
		free(remainder);
		return (NULL);
	}
	while (bytes != 0 && !ft_strchr(remainder, '\n'))
	{
		bytes = read(fd, reading, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (reading);
			free (remainder);
			return (NULL);
		}
		reading[bytes] = '\0';
		temp = ft_strjoin(remainder, reading);
		free(remainder);
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
	{
		free(remainder);
		return (NULL);
	}
	rest = ft_substr(remainder, i + 1, len - i);
	free(remainder);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder)
	{
		remainder = malloc(1 * sizeof(char));
		if (!remainder)
			return (NULL);
	}
	remainder = read_file(remainder, fd);
	if (!remainder)
		return (NULL);
	line = get_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}
