/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:39:18 by amsaoub           #+#    #+#             */
/*   Updated: 2023/10/15 14:52:30 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_err(char *str)
{
	str = 0;
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_count_char(char *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}

void	check_param_ext_h(char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (--len)
	{
		if (str[len] == '.')
		{
			if (str[len] == '.' && str[len + 1] == 'x' && str[len + 2] == 'p'
				&& str[len + 3] == 'm' && !str[len + 4])
				return ;
			ft_err("exten files");
		}
	}
	ft_err("exten files");
}

void	check_param_ext(t_map *all)
{
	check_param_ext_h(all->tex_paths.path_ea[1]);
	check_param_ext_h(all->tex_paths.path_so[1]);
	check_param_ext_h(all->tex_paths.path_we[1]);
	check_param_ext_h(all->tex_paths.path_no[1]);
}

void	init_images_h(t_mlx *mlx, t_textures *text, char *path)
{
	text->img = mlx_xpm_file_to_image(mlx->mlx, path, &text->width,
			&text->hieght);
	if (!text->img || text->width < 32 || text->width > 64 || text->hieght < 32
		|| text->hieght > 64)
		ft_err("xpm");
	text->tab = (unsigned int *)mlx_get_data_addr(text->img,
			&text->stract_img.pixel_bits, &text->stract_img.line_bytes,
			&text->stract_img.endian);
}
