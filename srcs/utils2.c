/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:00:20 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/16 15:02:07 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_values(t_mlx *mlx, t_cord *cord)
{
	mlx->player.x = (cord->x * 32) + 16;
	mlx->player.y = (cord->y * 32) + 16;
	mlx->player.turndirection = 0;
	mlx->player.walkdirection = 0;
	mlx->player.movespeed = 0;
	mlx->player.rotationspeed = 5 * (M_PI / 180);
	mlx->player.color = 0xff0000;
	mlx->map->final_map[mlx->cord.y][mlx->cord.x] = '0';
}

// char	*ft_substr_(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	l;
// 	char	*p;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	l = ft_strlen(s);
// 	if (len > l)
// 		len = l;
// 	if (start > l)
// 		len = 0;
// 	p = (char *)malloc(len + 1);
// 	if (!p)
// 		exit(1);
// 	while ((i < len) && s[start])
// 		p[i++] = s[start++];
// 	p[i] = '\0';
// 	return (p);
// }
