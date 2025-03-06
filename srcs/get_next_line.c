/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:44:19 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/14 18:47:50 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*readih(int fd, char *tmp)
{
	int		i;
	char	*buf;

	i = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		exit(1);
	while (!ft_strchr(tmp, '\n') && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		if (i == -1 && (*tmp == '\0' && i == 0))
		{
			free(buf);
			free(tmp);
			return (NULL);
		}
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_line1(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		line = ft_substr_s(buf, 0, i);
	else
		line = ft_substr(buf, 0, i);
	return (line);
}

char	*chyata(char *buf)
{
	char	*rem;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	else if (buf[i] == '\n')
		i++;
	j = ft_strlen(&buf[i]);
	rem = malloc(j + 1);
	if (!rem)
		exit(1);
	k = 0;
	while (buf[i])
		rem[k++] = buf[i++];
	rem[k] = '\0';
	free(buf);
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	if (!buf)
	{
		buf = malloc(1 * sizeof(char));
		if (!buf)
			exit(1);
		buf[0] = '\0';
	}
	buf = readih(fd, buf);
	line = get_line1(buf);
	buf = chyata(buf);
	return (line);
}
