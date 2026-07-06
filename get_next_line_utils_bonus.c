/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:49:13 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/02 11:58:14 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	string = malloc((size + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	if (start > size)
		len = 0;
	else if (size - start < len)
		len = size - start;
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*x;
	size_t			max;
	size_t			i;

	max = -1;
	if (nmemb != 0 && size > max / nmemb)
		return (NULL);
	x = malloc(nmemb * size);
	if (!x)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		x[i] = 0;
		i++;
	}
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
