/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:21:12 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 15:20:32 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_map(t_mlx *mlx)
{
	mlx->cord.x = 0;
	mlx->cord.y = 0;
	mlx->cord.color = 0;
	while (mlx->map->final_map[mlx->cord.y])
	{
		mlx->cord.x = 0;
		while (mlx->map->final_map[mlx->cord.y][mlx->cord.x])
		{
			setting_elements(mlx, \
			mlx->map->final_map[mlx->cord.y][mlx->cord.x], \
			&mlx->cord);
			mlx->cord.x++;
		}
		mlx->cord.y++;
	}
	draw_rays(mlx);
}

char	*ft_substr_s(char *str, size_t start, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	if (*str == '\0')
	{
		free(str);
		return (NULL);
	}
	s = malloc(len + 2);
	if (!s)
	{
		exit(1);
	}
	while (i < len && str[start])
		s[i++] = str[start++];
	s[i++] = '\n';
	s[i] = '\0';
	return (s);
}
