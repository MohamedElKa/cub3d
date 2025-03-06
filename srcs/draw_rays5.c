/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:19 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 13:13:55 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	other_intersections_v_c(t_mlx *mlx, double x_v, double y_v)
{
	double	x;
	double	y;

	x = x_v + mlx->rays.xstep_v;
	y = y_v + mlx->rays.ystep_v;
	mlx->rays.x_v = x;
	mlx->rays.y_v = y;
	if (check_wall_v(mlx, mlx->rays.x_v + 1, mlx->rays.y_v) == 1
		|| check_wall_v(mlx, mlx->rays.x_v - 1, mlx->rays.y_v) == 1)
		return (1);
	return (0);
}

int	first_intersection_h_c(t_mlx *mlx, double y)
{
	mlx->rays.yintercept = floor(mlx->player.y / 32) * 32;
	if (mlx->rays.isdown == 1)
	{
		mlx->rays.yintercept += 32;
		mlx->rays.ystep = 32;
	}
	else if (mlx->rays.isup == 1)
		mlx->rays.ystep = -32;
	y = mlx->rays.yintercept - (mlx->player.y);
	if (tan(mlx->rays.angle) == 0)
	{
		mlx->rays.xintercept = 0;
		mlx->rays.xstep = 0;
	}
	else
	{
		mlx->rays.xintercept = (mlx->player.x) + y / tan(mlx->rays.angle_c);
		mlx->rays.xstep = mlx->rays.ystep / tan(mlx->rays.angle_c);
	}
	mlx->rays.x_h = mlx->rays.xintercept;
	mlx->rays.y_h = mlx->rays.yintercept;
	if (check_wall(mlx, mlx->rays.xintercept, mlx->rays.yintercept + 1) == 1
		|| check_wall(mlx, mlx->rays.xintercept, mlx->rays.yintercept - 1) == 1)
		return (1);
	return (0);
}

void	first_intersection_vertical_c(t_mlx *mlx)
{
	mlx->rays.xintercept_v = floor(mlx->player.x / 32) * 32;
	if (mlx->rays.isright == 1)
	{
		mlx->rays.xintercept_v += 32;
		mlx->rays.xstep_v = 32;
	}
	else if (mlx->rays.isleft)
		mlx->rays.xstep_v = -32;
	mlx->rays.yintercept_v = mlx->player.y + (mlx->rays.xintercept_v
			- mlx->player.x) * tan(mlx->rays.angle_c);
	mlx->rays.ystep_v = mlx->rays.xstep_v * tan(mlx->rays.angle_c);
	mlx->rays.x_v = mlx->rays.xintercept_v;
	mlx->rays.y_v = mlx->rays.yintercept_v;
}

int	other_intersections_h_c(t_mlx *mlx, double x_h, double y_h)
{
	double	x;
	double	y;

	x = x_h + mlx->rays.xstep;
	y = y_h + mlx->rays.ystep;
	mlx->rays.x_h = x;
	mlx->rays.y_h = y;
	if (check_wall(mlx, mlx->rays.x_h, mlx->rays.y_h + 1) == 1
		|| check_wall(mlx, mlx->rays.x_h, mlx->rays.y_h - 1) == 1)
		return (1);
	return (0);
}

void	horizontal_intersections_c(t_mlx *mlx)
{
	if (first_intersection_h_c(mlx, 0) == 1)
		return ;
	if (other_intersections_h_c(mlx, mlx->rays.xintercept,
			mlx->rays.yintercept) == 1)
		return ;
	while (1)
	{
		if (other_intersections_h_c(mlx, mlx->rays.x_h, mlx->rays.y_h) == 1)
			break ;
	}
}
