/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:13:00 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 14:07:51 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	vertical_intersections_c(t_mlx *mlx)
{
	first_intersection_vertical_c(mlx);
	if (check_wall_v(mlx, mlx->rays.x_v + 1, mlx->rays.y_v) == 1
		|| check_wall_v(mlx, mlx->rays.x_v - 1, mlx->rays.y_v) == 1)
		return ;
	if (other_intersections_v_c(mlx, mlx->rays.xintercept_v,
			mlx->rays.yintercept_v) == 1)
		return ;
	while (1)
	{
		if (other_intersections_v_c(mlx, mlx->rays.x_v, mlx->rays.y_v) == 1)
			break ;
	}
}

char	**ft_split_exp(char const *s, char c, int i, int j)
{
	char	**p;

	if (!s)
		return (NULL);
	p = malloc(sizeof(char *) * 3);
	if (!p)
		exit(1);
	while (s[i])
	{
		if (s[i] == c)
		{
			p[++j] = ft_substr(s, 0, i);
			s += ++i;
			break ;
		}
		i++;
	}
	while (s[i++])
		;
	p[++j] = ft_substr(s, 0, i);
	p[++j] = NULL;
	return (p);
}
