/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:45:07 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/14 18:46:41 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		exit(1);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(const char *str, size_t start, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	if (*str == '\0')
	{
		return (NULL);
	}
	s = malloc(len + 1);
	if (!s)
		exit(1);
	while (i < len && str[start])
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	if (!dst || !src)
		return (0);
	k = ft_strlen((char *)src);
	i = 0;
	if (dstsize == 0)
		return (k);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (k);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*ptr;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	i = ft_strlen(s1);
	i++;
	ptr = (char *)malloc(i * sizeof(char));
	if (!ptr)
		exit(1);
	ft_strlcpy(ptr, s1, i);
	return (ptr);
}
