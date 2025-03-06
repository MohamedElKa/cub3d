/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:19:38 by amsaoub           #+#    #+#             */
/*   Updated: 2023/10/14 18:48:00 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strrchr(char *s, int c)
{
	int		len;
	char	data;

	data = (char)c;
	len = ft_strlen(s);
	if (data == 0)
		return ((char *)&s[len]);
	len--;
	while (len >= 0)
	{
		if ((char)s[len] == data)
			return ((char *)(s + len));
		len--;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (end > start && ft_strrchr(set, s1[end - 1]))
		end--;
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		exit(1);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

int	ft_atoi(char *str)
{
	int				i;
	unsigned int	res;
	int				sign;
	int				k;

	i = 0;
	res = 0;
	sign = 1;
	k = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = sign * -1;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i++] - '0');
		k++;
	}
	return (res * sign);
}
