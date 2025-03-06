/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:35:01 by amsaoub           #+#    #+#             */
/*   Updated: 2023/10/17 14:40:06 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_images(t_mlx *mlx)
{
	mlx->textures = malloc(sizeof(t_textures) * 4);
	if (!mlx->textures)
		exit(1);
	init_images_h(mlx, &mlx->textures[0], mlx->map->tex_paths.path_ea[1]);
	init_images_h(mlx, &mlx->textures[1], mlx->map->tex_paths.path_no[1]);
	init_images_h(mlx, &mlx->textures[2], mlx->map->tex_paths.path_so[1]);
	init_images_h(mlx, &mlx->textures[3], mlx->map->tex_paths.path_we[1]);
}

int	return_text_pixle_color(int x, int y, unsigned int *tab, int tex_h)
{
	unsigned int	a;

	a = tab[(tex_h * y) + x];
	return (a);
}

int	get_colors_values_h(char **tab)
{
	int	color;
	int	r;
	int	g;
	int	b;

	if (!ft_strlen(tab[0]))
		ft_err("df");
	r = ft_atoi(tab[0]);
	g = ft_atoi(tab[1]);
	b = ft_atoi(tab[2]);
	color = 0;
	color = (r << 16) + (g << 8) + b;
	return (color);
}

void	get_colors_values(t_mlx *mlx)
{
	mlx->colc = get_colors_values_h(mlx->map->colors.c);
	mlx->colf = get_colors_values_h(mlx->map->colors.f);
	free_tab(mlx->map->colors.c);
	free_tab(mlx->map->colors.f);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
