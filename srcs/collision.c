/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:06:04 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 14:41:52 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	collision(t_mlx *mlx, double tmp_x, double tmp_y, double angle)
{
	size_t	x;
	size_t	y;
	int		x_p;
	int		y_p;

	mlx->player.col_angle = normalize_angle(angle);
	x_p = floor(mlx->player.x / 32);
	y_p = floor(mlx->player.y / 32);
	x = floor(tmp_x / 32);
	y = floor(tmp_y / 32);
	if (mlx->map->final_map[(int)y_p][(int)x_p] == '1' || \
	((mlx->map->final_map[(int)y][(int)x_p] == '1') \
	&& (mlx->map->final_map[(int)y_p][(int)x] == '1')))
		return (1);
	return (0);
}

void	check_sides(t_mlx *mlx, double tmp_x, double tmp_y)
{
	if (collision(mlx, tmp_x, tmp_y, mlx->player.rotationangle \
	+ M_PI / 2) && \
	mlx->player.right != 0)
	{
		mlx->player.x = tmp_x;
		mlx->player.y = tmp_y;
	}
	if (collision(mlx, tmp_x, tmp_y, mlx->player.rotationangle \
	- M_PI / 2) && \
	mlx->player.left != 0)
	{
		mlx->player.x = tmp_x;
		mlx->player.y = tmp_y;
	}
}

void	col(t_mlx *mlx, double tmp_x, double tmp_y)
{
	if ((int)cast_col(mlx) < 10 && mlx->player.movespeed == 4)
	{
		mlx->player.x = tmp_x;
		mlx->player.y = tmp_y;
	}
	if (collision(mlx, tmp_x, tmp_y, mlx->player.rotationangle \
	) && \
	mlx->player.movespeed == 4)
	{
		mlx->player.x = tmp_x;
		mlx->player.y = tmp_y;
	}
	if (collision(mlx, tmp_x, tmp_y, mlx->player.rotationangle \
	+ M_PI) && \
	mlx->player.movespeed == -4)
	{
		mlx->player.x = tmp_x;
		mlx->player.y = tmp_y;
	}
	check_sides(mlx, tmp_x, tmp_y);
}

void	check_collision(t_mlx *mlx, double tmp_x, double tmp_y)
{
	if (mlx->player.movespeed == 4)
	{
		mlx->player.x += cos(mlx->player.rotationangle) * mlx->player.movespeed;
		mlx->player.y += sin(mlx->player.rotationangle) * mlx->player.movespeed;
	}
	if (mlx->player.movespeed == -4)
	{
		mlx->player.x += cos(mlx->player.rotationangle + M_PI) * 4;
		mlx->player.y += sin(mlx->player.rotationangle + M_PI) * 4;
	}
	if (mlx->player.left != 0)
	{
		mlx->player.x += cos(mlx->player.rotationangle - (M_PI / 2)) * 2;
		mlx->player.y += sin(mlx->player.rotationangle - (M_PI / 2)) * 2;
	}
	if (mlx->player.right != 0)
	{
		mlx->player.x += cos(mlx->player.rotationangle + (M_PI / 2)) * 4;
		mlx->player.y += sin(mlx->player.rotationangle + (M_PI / 2)) * 4;
	}
	col(mlx, tmp_x, tmp_y);
}
