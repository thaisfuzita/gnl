/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:37:12 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/30 18:49:07 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*reading;
	static char	*remainder;

	if (remainder == NULL)
		return;
	reading = malloc(BUFFER_SIZE + 1);
	if (!reading)
		return (NULL);
	read_file(reading, remainder, fd);
	return (line);
}

static read_file(char *reading, char *remainder, int fd)
{
	char *line;
	int bytes;
	int	i;
	char	*end;

	while ()
	bytes = read(fd, reading, BUFFER_SIZE);
	if (bytes == -1 || bytes == 0)
		return;
	i = 0;
	end = ft_strchr(reading, '\n');
	
	if (line == NULL)
		return;
}

static get_line()
{
	
}

static update_remainder()
{
	
}
