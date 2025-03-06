/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:21:39 by amsaoub           #+#    #+#             */
/*   Updated: 2023/10/15 11:00:31 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	pars_h_2_h(t_map *all, int *i, int *j)
{
	if (count_rows(all->map) != *i + 1)
	{
		if (*j == 0 || !ft_isprint(all->map[*i + 1][*j])
			|| !ft_isprint(all->map[*i - 1][*j]) || !ft_isprint(all->map[*i][*j
				+ 1]))
			ft_err("walls problem");
	}
	if (count_rows(all->map) == *i + 1)
	{
		if (!ft_isprint(all->map[*i - 1][*j]) || !ft_isprint(all->map[*i][*j
				+ 1]) || !ft_isprint(all->map[*i][*j - 1])
			|| count_rows(all->map) == *i + 1)
			ft_err("walls problem");
	}
	if (*j != 0 && count_rows(all->map) != *i + 1)
	{
		if (!ft_isprint(all->map[*i + 1][*j]) || !ft_isprint(all->map[*i
				- 1][*j]) || !ft_isprint(all->map[*i][*j + 1])
			|| !ft_isprint(all->map[*i][*j - 1]))
			ft_err("walls problem");
	}
}

void	pars_h_2(t_map *all, int *i, int *j)
{
	int	temp_up;
	int	temp_down;

	temp_up = 0;
	temp_down = 0;
	if (all->map[*i][*j] == '0' || all->map[*i][*j] == 'N'
		|| all->map[*i][*j] == 'S' || all->map[*i][*j] == 'E'
		|| all->map[*i][*j] == 'W')
	{
		if (*j != 0)
			temp_up = ft_strlen(all->map[*i - 1]);
		if (count_rows(all->map) != *i + 1)
			temp_down = ft_strlen(all->map[*i + 1]);
		if (*j > temp_up || *j > temp_down)
			ft_err("walls problem");
		pars_h_2_h(all, i, j);
	}
}

void	pars(t_map *all)
{
	int	i;
	int	j;
	int	param;

	param = 0;
	j = 0;
	pars_h_1(all, &i, &param);
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			pars_h_2(all, &i, &j);
			j++;
		}
		i++;
	}
}

void	parse_param1(t_map *all, int i)
{
	if (!ft_strncmp("NO ", all->map_param[i], 3))
	{
		if (all->conter_param.no)
			free_tab(all->tex_paths.path_no);
		all->tex_paths.path_no = (char **)malloc(sizeof(char *) * 3);
		if (!all->tex_paths.path_no)
			exit(1);
		all->tex_paths.path_no[0] = ft_strdup("NO");
		all->tex_paths.path_no[1] = ft_strtrim(&all->map_param[i][3], " \n");
		all->tex_paths.path_no[2] = 0;
		all->conter_param.no++;
	}
	if (!ft_strncmp("SO ", all->map_param[i], 3))
	{
		if (all->conter_param.so)
			free_tab(all->tex_paths.path_so);
		all->tex_paths.path_so = (char **)malloc(sizeof(char *) * 3);
		if (!all->tex_paths.path_so)
			exit(1);
		all->tex_paths.path_so[0] = ft_strdup("SO");
		all->tex_paths.path_so[1] = ft_strtrim(&all->map_param[i][3], " \n");
		all->tex_paths.path_so[2] = 0;
		all->conter_param.so++;
	}
}

void	parse_param2(t_map *all, int i)
{
	if (!ft_strncmp("WE ", all->map_param[i], 3))
	{
		if (all->conter_param.we)
			free_tab(all->tex_paths.path_we);
		all->tex_paths.path_we = (char **)malloc(sizeof(char *) * 3);
		if (!all->tex_paths.path_we)
			exit(1);
		all->tex_paths.path_we[0] = ft_strdup("WE");
		all->tex_paths.path_we[1] = ft_strtrim(&all->map_param[i][3], " \n");
		all->tex_paths.path_we[2] = 0;
		all->conter_param.we++;
	}
	if (!ft_strncmp("EA ", all->map_param[i], 3))
	{
		if (all->conter_param.ea)
			free_tab(all->tex_paths.path_ea);
		all->tex_paths.path_ea = (char **)malloc(sizeof(char *) * 3);
		if (!all->tex_paths.path_ea)
			exit(1);
		all->tex_paths.path_ea[0] = ft_strdup("EA");
		all->tex_paths.path_ea[1] = ft_strtrim(&all->map_param[i][3], " \n");
		all->tex_paths.path_ea[2] = 0;
		all->conter_param.ea++;
	}
}

// void	pars(t_map *all)
// {
// 	int	i;
// 	int	j;
// 	int	param;
// 	int	temp_up;
// 	int	temp_down;

// 	i = 0;
// 	j = 0;
// 	param = 0;
// 	temp_up = 0;
// 	temp_down = 0;
// 	while (all->map[i])
// 	{
// 		if (is_str_print(all->map[i]))
// 		{
// 			param++;
// 			all->map_param[param - 1] = all->map[i];
// 		}
// 		if (param > 6)
// 		{
// 			all->map_param[6] = NULL;
// 			break ;
// 		}
// 		i++;
// 	}
// 	if (param < 6)
// 		ft_err("no enough pram");
// 	if (!(all->map[i]))
// 		ft_err("err map");
// 	while (!is_str_print(all->map[i]))
// 		i++;
// 	all->map_bin = &all->map[i];
// 	while (all->map[i])
// 	{
// 		j = 0;
// 		while (all->map[i][j])
// 		{
// 			if (all->map[i][j] == '0' || all->map[i][j] == 'N'
// 				|| all->map[i][j] == 'S' || all->map[i][j] == 'E'
// 				|| all->map[i][j] == 'W')
// 			{
// 				if (j != 0)
// 					temp_up = ft_strlen(all->map[i - 1]);
// 				if (count_rows(all->map) != i + 1)
// 					temp_down = ft_strlen(all->map[i + 1]);
// 				if (j > temp_up || j > temp_down)
// 					ft_err("walls problem");
// 				if (count_rows(all->map) != i + 1)
// 				{
// 					if (j == 0 || !ft_isprint(all->map[i + 1][j])
// 						|| !ft_isprint(all->map[i - 1][j])
// 						|| !ft_isprint(all->map[i][j + 1]))
// 						ft_err("walls problem");
// 				}
// 				if (count_rows(all->map) == i + 1)
// 				{
// 					if (!ft_isprint(all->map[i - 1][j])
// 						|| !ft_isprint(all->map[i][j + 1])
// 						|| !ft_isprint(all->map[i][j - 1])
// 						|| count_rows(all->map) == i + 1)
// 						ft_err("walls problem");
// 				}
// 				if (j != 0 && count_rows(all->map) != i + 1)
// 				{
// 					if (!ft_isprint(all->map[i + 1][j])
// 						|| !ft_isprint(all->map[i - 1][j])
// 						|| !ft_isprint(all->map[i][j + 1])
// 						|| !ft_isprint(all->map[i][j - 1]))
// 						ft_err("walls problem");
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }