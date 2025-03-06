/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:22:33 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/16 15:00:57 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < mlx->size_x) && (y > 0 && y < mlx->size_y))
	{
		dst = mlx->img.buffer + (y * mlx->img.line_bytes + x
				* (mlx->img.pixel_bits / 8));
		*(unsigned int *)dst = color;
	}
}

int	rows_calcul(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	cols_calcul(char **map)
{
	int		i;
	size_t	max;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) >= max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	fill_data(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->map->cols = ft_strlen(mlx->map->final_map[0]);
	mlx->map->rows = rows_calcul(mlx->map->final_map);
	mlx->size_x = 1024;
	mlx->size_y = 800;
	mlx->title = "cub3d";
	mlx->win_ptr = mlx_new_window(mlx->mlx, mlx->size_x, mlx->size_y,
			mlx->title);
	mlx->img.image = mlx_new_image(mlx->mlx, mlx->size_x, mlx->size_y);
	mlx->img.buffer = mlx_get_data_addr(mlx->img.image, &mlx->img.pixel_bits,
			&mlx->img.line_bytes, &mlx->img.endian);
	mlx->rays.fovangle = 60 * (M_PI / 180);
	mlx->rays.wallstrip = 4;
	mlx->rays.numrays = mlx->size_x / mlx->rays.wallstrip;
	mlx->rays.ystep = 0;
	mlx->rays.xstep = 0;
}

void	setting_elements(t_mlx *mlx, char c, t_cord *cord)
{
	static int	flag;

	if (c == '0')
		cord->color = 0x000000;
	else if (c == '1')
		cord->color = 0xffffff;
	else if ((c == 'S' || c == 'W' || c == 'N' || c == 'E') && flag < 1)
	{
		if (c == 'S')
			mlx->player.rotationangle = 90 * (M_PI / 180);
		else if (c == 'W')
			mlx->player.rotationangle = 180 * (M_PI / 180);
		if (c == 'N')
			mlx->player.rotationangle = 270 * (M_PI / 180);
		if (c == 'E')
			mlx->player.rotationangle = 360 * (M_PI / 180);
		flag++;
		set_values(mlx, cord);
	}
}
