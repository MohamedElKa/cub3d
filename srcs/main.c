/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:48:11 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 14:09:22 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	pars_init(t_mlx *mlx)
{
	mlx->map->map_param = (char **)malloc(sizeof(char *) * 7);
	if (!mlx->map->map_param)
		exit(1);
	mlx->map->map_param[6] = 0;
}

void	parsing_h(t_mlx *mlx, char **av)
{
	int		fd;
	char	*map;
	char	*str;
	char	*temp;

	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
		exit(1);
	fd = open(av[1], O_RDWR, 0777);
	map = ft_strdup("");
	str = get_next_line(fd);
	pars_init(mlx);
	temp = ft_to_string(mlx->k);
	while (str)
	{
		map = ft_strjoin(map, temp);
		map = ft_strjoin(map, str);
		free(str);
		str = get_next_line(fd);
	}
	free(temp);
	mlx->map->map = ft_split(map, mlx->k);
	if (!mlx->map->map)
		ft_err("no map");
	free(map);
}

int	keyrelease(int keycode, t_mlx *mlx)
{
	int	a;

	a = keycode;
	mlx->player.turndirection = 0;
	mlx->player.movespeed = 0;
	mlx->player.left = 0;
	mlx->player.right = 0;
	return (0);
}

void	parsing(t_mlx *mlx, int ac, char **av)
{
	check_exten(av[1], ac);
	parsing_h(mlx, av);
	pars(mlx->map);
	parse_param(mlx->map);
	check_param_ext(mlx->map);
	get_final_map(mlx->map, 0, 0);
	check_caracters(mlx->map);
	get_values_colors(mlx->map);
	check_colors_values(mlx->map);
	check_colors_values_h(mlx->map);
	get_colors_values(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit(1);
	mlx->k = (char)22;
	mlx->player.left = 0;
	mlx->player.right = 0;
	parsing(mlx, argc, argv);
	fill_data(mlx);
	init_images(mlx);
	draw_map(mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, &keypress, mlx);
	mlx_hook(mlx->win_ptr, 3, 1L << 1, &keyrelease, mlx);
	mlx_loop_hook(mlx->mlx, &player_movements, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 0, mouse_hook, mlx);
	mlx_loop(mlx->mlx);
}
