/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:06:35 by amsaoub           #+#    #+#             */
/*   Updated: 2023/10/14 18:24:45 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_caracters_h(t_map *all, int i, int j, int cp)
{
	if (all->final_map[i][j] != '0' && all->final_map[i][j] != '1'
		&& all->final_map[i][j] != 'E' && all->final_map[i][j] != 'N'
		&& all->final_map[i][j] != 'S' && all->final_map[i][j] != 'W'
		&& all->final_map[i][j] != ' ')
		ft_err("charac problem");
	if (all->final_map[i][j] == 'W' || all->final_map[i][j] == 'N'
		|| all->final_map[i][j] == 'E' || all->final_map[i][j] == 'S')
	{
		all->p_symbole = all->final_map[i][j];
		cp++;
	}
	return (cp);
}

void	check_caracters(t_map *all)
{
	int	i;
	int	j;
	int	cp;

	i = 0;
	j = 0;
	cp = 0;
	while (all->final_map[i])
	{
		j = 0;
		while (all->final_map[i][j])
		{
			cp = check_caracters_h(all, i, j, cp);
			j++;
		}
		i++;
	}
	if (cp == 0 || cp > 1)
		ft_err("player");
}

void	get_values_colors_h(t_map *all, int i)
{
	char	*temp;

	if (all->map_param[i][0] == 'F')
	{
		if (ft_count_char(all->map_param[i], ',') > 2)
			ft_err("too many ,");
		temp = all->map_param[i];
		all->map_param[i] = ft_strtrim(all->map_param[i], " \n");
		free(temp);
		all->colors.f = ft_split(&all->map_param[i][2], ',');
	}
	else if (all->map_param[i][0] == 'C')
	{
		if (ft_count_char(all->map_param[i], ',') > 2)
			ft_err("too many ,");
		temp = all->map_param[i];
		all->map_param[i] = ft_strtrim(all->map_param[i], " \n");
		free(temp);
		all->colors.c = ft_split(&all->map_param[i][2], ',');
	}
}

void	get_values_colors(t_map *all)
{
	int	i;

	i = 0;
	while (all->map_param[i])
	{
		get_values_colors_h(all, i);
		i++;
	}
	if (count_rows(all->colors.c) != 3 || count_rows(all->colors.f) != 3)
		ft_err("err val");
}
