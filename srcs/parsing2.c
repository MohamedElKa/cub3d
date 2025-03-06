/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:21:32 by amsaoub           #+#    #+#             */
/*   Updated: 2023/10/15 11:00:37 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	ft_isprint(int c)
{
	if (c > ' ' && c < 127)
		return (1);
	else
		return (0);
}

int	is_str_print(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_isprint(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_to_string(char c)
{
	char	*str;

	str = malloc(2);
	if (!str)
		exit(1);
	str[0] = c;
	str[1] = 0;
	return (str);
}

void	get_final_map(t_map *all, int i, int j)
{
	while (all->map_bin[i] && all->map_bin[i][0] != '\n')
		i++;
	all->final_map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!all->final_map)
		exit(1);
	all->final_map[i] = 0;
	while (j < i)
	{
		all->final_map[j] = ft_strtrim(all->map_bin[j], "\n");
		j++;
	}
	while (all->map_bin[i])
	{
		j = 0;
		while (all->map_bin[i][j])
		{
			if (all->map_bin[i][j] != '\n')
				ft_err("somthing after map");
			j++;
		}
		i++;
	}
}
