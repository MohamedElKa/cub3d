/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:19 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 15:32:12 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	other_intersections_h(t_mlx *mlx, double x_h, double y_h)
{
	double	x;
	double	y;

	x = x_h + mlx->rays.xstep;
	y = y_h + mlx->rays.ystep;
	mlx->rays.x_h = x;
	mlx->rays.y_h = y;
	if (check_wall(mlx, mlx->rays.x_h, mlx->rays.y_h) == 1
		|| check_wall(mlx, mlx->rays.x_h, mlx->rays.y_h - 1) == 1)
		return (1);
	return (0);
}

void	horizontal_intersections(t_mlx *mlx)
{
	if (first_intersection_h(mlx, 0) == 1)
		return ;
	if (other_intersections_h(mlx, mlx->rays.xintercept,
			mlx->rays.yintercept) == 1)
		return ;
	while (1)
	{
		if (other_intersections_h(mlx, mlx->rays.x_h, mlx->rays.y_h) == 1)
			break ;
	}
}
