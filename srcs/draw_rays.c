/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:19 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 15:33:10 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	normalize_angle(double angle)
{
	while (angle < 0)
	{
		angle += 2 * M_PI;
	}
	while (angle >= 2 * M_PI)
	{
		angle -= 2 * M_PI;
	}
	return (angle);
}

int	check_wall(t_mlx *mlx, int xo, int yo)
{
	size_t	x;
	size_t	y;

	x = (floor(xo / 32) * 32) / 32;
	y = (floor(yo / 32) * 32) / 32;
	if (!(y >= 0 && y < mlx->map->rows))
		return (1);
	if ((x >= 0 && x < ft_strlen(mlx->map->final_map[y])))
	{
		if (mlx->map->final_map[y][x] == '1')
			return (1);
	}
	else if (!(x >= 0 && x < ft_strlen(mlx->map->final_map[y])))
		return (-1);
	return (0);
}

int	check_wall_v(t_mlx *mlx, int xo, int yo)
{
	size_t	x;
	size_t	y;

	x = (floor(xo / 32) * 32) / 32;
	y = (floor(yo / 32) * 32) / 32;
	if (!(y >= 0 && y < mlx->map->rows))
		return (1);
	if ((x >= 0 && x < ft_strlen(mlx->map->final_map[y])))
	{
		if (mlx->map->final_map[y][x] == '1')
			return (1);
	}
	else if (!(x >= 0 && x < ft_strlen(mlx->map->final_map[y])))
		return (-1);
	return (0);
}

int	first_intersection_h(t_mlx *mlx, double y)
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
		mlx->rays.xintercept = (mlx->player.x) + y / tan(mlx->rays.angle);
		mlx->rays.xstep = mlx->rays.ystep / tan(mlx->rays.angle);
	}
	mlx->rays.x_h = mlx->rays.xintercept;
	mlx->rays.y_h = mlx->rays.yintercept;
	if (check_wall(mlx, mlx->rays.xintercept, mlx->rays.yintercept) == 1 || \
	check_wall(mlx, mlx->rays.xintercept, mlx->rays.yintercept - 1) == 1)
		return (1);
	return (0);
}

void	first_intersection_vertical(t_mlx *mlx)
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
			- mlx->player.x) * tan(mlx->rays.angle);
	mlx->rays.ystep_v = mlx->rays.xstep_v * tan(mlx->rays.angle);
	mlx->rays.x_v = mlx->rays.xintercept_v;
	mlx->rays.y_v = mlx->rays.yintercept_v;
}
