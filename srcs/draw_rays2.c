/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:19 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 15:20:49 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cast_h(t_mlx *mlx)
{
	if (mlx->rays.angle < M_PI * 2 && M_PI > mlx->rays.angle)
	{
		mlx->offsetx = fmod(((mlx->rays.x_h * mlx->textures[2].width) / 32),
				mlx->textures[2].width);
		mlx->height_text = mlx->textures[2].hieght;
		mlx->tab_img = mlx->textures[2].tab;
	}
	else
	{
		mlx->offsetx = fmod(((mlx->rays.x_h * mlx->textures[1].width) / 32),
				mlx->textures[1].width);
		mlx->height_text = mlx->textures[1].hieght;
		mlx->tab_img = mlx->textures[1].tab;
	}
}

void	cast(t_mlx *mlx)
{
	double	d_h;
	double	d_v;
	double	raydistance;
	double	wallheight;

	horizontal_intersections(mlx);
	vertical_intersections(mlx);
	d_h = distance_h(mlx);
	d_v = distance_v(mlx);
	if (d_h >= d_v)
	{
		cast_v(mlx);
		raydistance = d_v;
	}
	else
	{
		cast_h(mlx);
		raydistance = d_h;
	}
	if (raydistance == 0)
		raydistance = 1;
	wallheight = mlx->size_y * 32 / (raydistance * cos(mlx->rays.angle
				- mlx->player.rotationangle));
	draw_walls_ayman(mlx, wallheight, mlx->height_text, mlx->tab_img);
}

void	draw_rays(t_mlx *mlx)
{
	int		i;
	double	rotation;

	i = 0;
	mlx->rays.fovangle = normalize_angle(mlx->rays.fovangle);
	rotation = mlx->player.rotationangle - mlx->rays.fovangle / 2.0;
	while (i <= mlx->size_x)
	{
		mlx->rays.angle = normalize_angle(rotation);
		mlx->rays.isdown = mlx->rays.angle > 0 && mlx->rays.angle < M_PI;
		mlx->rays.isup = !mlx->rays.isdown;
		mlx->rays.isright = mlx->rays.angle < 0.5 * M_PI
			|| mlx->rays.angle > 1.5 * M_PI;
		mlx->rays.isleft = !mlx->rays.isright;
		cast(mlx);
		rotation += mlx->rays.fovangle / mlx->size_x;
		mlx->rays.i = (double)i;
		i++;
	}
}

void	draw_walls_h(t_mlx *mlx, double y1, double wallheight, double x)
{
	y1 = 0;
	x = mlx->rays.i;
	while (y1 <= (mlx->size_y / 2) - (wallheight / 2))
	{
		my_mlx_pixel_put(mlx, x, y1, mlx->colc);
		y1++;
	}
	y1 = (double)(mlx->size_y / 2) + (wallheight / 2);
	x = mlx->rays.i;
	while (y1 < mlx->size_y)
	{
		my_mlx_pixel_put(mlx, x, y1, mlx->colf);
		y1++;
	}
}

void	draw_walls_ayman(t_mlx *mlx, double wallheight, int height_text,
		unsigned int *image)
{
	double	x;
	double	y1;
	double	top;
	double	y2;
	int		color;

	x = mlx->rays.i;
	y1 = (mlx->size_y / 2) - (wallheight / 2);
	y2 = (mlx->size_y / 2) + (wallheight / 2);
	top = y1;
	while (y1 < y2)
	{
		mlx->offsety = ((y1 - top) * height_text) / wallheight;
		color = return_text_pixle_color(mlx->offsetx, mlx->offsety, image,
				height_text);
		my_mlx_pixel_put(mlx, x, y1, color);
		y1++;
	}
	draw_walls_h(mlx, y1, wallheight, x);
}
