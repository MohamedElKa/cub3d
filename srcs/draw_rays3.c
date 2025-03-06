/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:19 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 15:33:41 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	other_intersections_v(t_mlx *mlx, double x_v, double y_v)
{
	double	x;
	double	y;

	x = x_v + mlx->rays.xstep_v;
	y = y_v + mlx->rays.ystep_v;
	mlx->rays.x_v = x;
	mlx->rays.y_v = y;
	if (check_wall_v(mlx, mlx->rays.x_v, mlx->rays.y_v) == 1
		|| check_wall_v(mlx, mlx->rays.x_v - 1, mlx->rays.y_v) == 1)
		return (1);
	return (0);
}

void	vertical_intersections(t_mlx *mlx)
{
	first_intersection_vertical(mlx);
	if (check_wall_v(mlx, mlx->rays.x_v, mlx->rays.y_v) == 1
		|| check_wall_v(mlx, mlx->rays.x_v - 1, mlx->rays.y_v) == 1)
		return ;
	if (other_intersections_v(mlx, mlx->rays.xintercept_v,
			mlx->rays.yintercept_v) == 1)
		return ;
	while (1)
	{
		if (other_intersections_v(mlx, mlx->rays.x_v, mlx->rays.y_v) == 1)
			break ;
	}
}

double	distance_h(t_mlx *mlx)
{
	double	d;

	d = sqrt((mlx->rays.x_h - mlx->player.x) * (mlx->rays.x_h - mlx->player.x)
			+ ((mlx->rays.y_h - mlx->player.y) * (mlx->rays.y_h
					- mlx->player.y)));
	if (d < 0)
		return (INT32_MAX);
	return (d);
}

double	distance_v(t_mlx *mlx)
{
	double	d;

	d = sqrt((mlx->rays.x_v - mlx->player.x) * (mlx->rays.x_v - mlx->player.x)
			+ ((mlx->rays.y_v - mlx->player.y) * (mlx->rays.y_v
					- mlx->player.y)));
	if (d < 0)
		return (INT32_MAX);
	return (d);
}

void	cast_v(t_mlx *mlx)
{
	if (mlx->rays.angle > M_PI * 0.5 && M_PI * 1.5 > mlx->rays.angle)
	{
		mlx->offsetx = fmod(((mlx->rays.y_v * mlx->textures[3].width) / 32),
				mlx->textures[3].width);
		mlx->height_text = mlx->textures[3].hieght;
		mlx->tab_img = mlx->textures[3].tab;
	}
	else
	{
		mlx->offsetx = fmod(((mlx->rays.y_v * mlx->textures[0].width) / 32),
				mlx->textures[0].width);
		mlx->height_text = mlx->textures[0].hieght;
		mlx->tab_img = mlx->textures[0].tab;
	}
}
