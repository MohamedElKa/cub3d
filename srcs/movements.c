/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:19:25 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 13:06:29 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	reset_image(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			my_mlx_pixel_put(mlx, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int	player_movements(t_mlx *mlx)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = mlx->player.x;
	tmp_y = mlx->player.y;
	mlx->player.rotationangle += mlx->player.turndirection
		* mlx->player.rotationspeed;
	mlx->player.rotationangle = normalize_angle(mlx->player.rotationangle);
	check_collision(mlx, tmp_x, tmp_y);
	reset_image(mlx);
	draw_map(mlx);
	mlx_clear_window(mlx->mlx, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx, mlx->win_ptr, mlx->img.image, 0, 0);
	return (0);
}

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 124)
		mlx->player.turndirection = 1;
	if (keycode == 123)
		mlx->player.turndirection = -1;
	if (keycode == 13)
		mlx->player.movespeed = 4;
	if (keycode == 1)
		mlx->player.movespeed = -4;
	if (keycode == 0)
		mlx->player.left = 1;
	if (keycode == 2)
		mlx->player.right = 1;
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win_ptr);
		exit(0);
	}
	return (0);
}
