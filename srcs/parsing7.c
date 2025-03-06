/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:03:19 by amsaoub           #+#    #+#             */
/*   Updated: 2023/10/16 11:54:25 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	pars_h_1(t_map *all, int *i, int *param)
{
	*i = 0;
	while (all->map[*i])
	{
		if (is_str_print(all->map[*i]))
		{
			(*param)++;
			all->map_param[(*param) - 1] = all->map[*i];
		}
		if ((*param) > 6)
		{
			all->map_param[6] = NULL;
			break ;
		}
		(*i)++;
	}
	if (*param < 6)
		ft_err("no enough pram");
	if (!(all->map[*i]))
		ft_err("err map");
	while (!is_str_print(all->map[*i]))
		(*i)++;
	all->map_bin = &all->map[*i];
}

void	parse_param(t_map *all)
{
	int	i;

	all->conter_param.c = 0;
	all->conter_param.f = 0;
	all->conter_param.we = 0;
	all->conter_param.so = 0;
	all->conter_param.no = 0;
	all->conter_param.ea = 0;
	i = 0;
	while (all->map_param[i])
	{
		all->map_param[i] = ft_strtrim(all->map_param[i], " ");
		parse_param1(all, i);
		parse_param2(all, i);
		if (!ft_strncmp("C ", all->map_param[i], 2))
			all->conter_param.c++;
		if (!ft_strncmp("F ", all->map_param[i], 2))
			all->conter_param.f++;
		i++;
	}
	if (!all->conter_param.c || !all->conter_param.f || !all->conter_param.we
		|| !all->conter_param.ea || !all->conter_param.so
		|| !all->conter_param.no)
		ft_err("no enough param");
}

int	mouse_hook(t_mlx *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win_ptr);
	exit(0);
}
