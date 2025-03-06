/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:47:02 by amsaoub           #+#    #+#             */
/*   Updated: 2023/10/15 14:51:02 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_colors_values_2(t_map *all)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = all->colors.f[i];
	all->colors.f[i] = ft_strtrim(all->colors.f[i], " ");
	free(temp);
	while (all->colors.f[i])
	{
		j = 0;
		while (all->colors.f[i][j])
		{
			if (all->colors.f[i][j] < '0' || all->colors.f[i][j] > '9')
			{
				free_tab(all->colors.f);
				ft_err("err val 3");
			}
			j++;
		}
		i++;
	}
}

void	check_colors_values(t_map *all)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = all->colors.c[i];
	all->colors.c[i] = ft_strtrim(all->colors.c[i], " ");
	free(temp);
	while (all->colors.c[i])
	{
		j = 0;
		while (all->colors.c[i][j])
		{
			if (all->colors.c[i][j] < '0' || all->colors.c[i][j] > '9')
			{
				ft_err("err val 2");
			}
			j++;
		}
		i++;
	}
	check_colors_values_2(all);
}

void	check_colors_values_h(t_map *all)
{
	int	i;

	i = 0;
	while (all->colors.c[i])
	{
		if (ft_atoi(all->colors.c[i]) > 255 || ft_atoi(all->colors.f[i]) > 255)
		{
			free_tab(all->colors.c);
			free_tab(all->colors.f);
			ft_err("err val 4");
		}
		i++;
	}
}

void	check_exten(char *str, int ac)
{
	size_t	i;
	size_t	len;

	if (ac != 2)
		ft_err("no map");
	len = ft_strlen(str);
	i = 0;
	while (--len && ac == 2)
	{
		if (str[len] == '.')
		{
			if (str[len] == '.' && str[len + 1] == 'c' && str[len + 2] == 'u'
				&& str[len + 3] == 'b' && !str[len + 4])
				return ;
			ft_err("exten problem");
		}
	}
	ft_err("exten problem");
}

int	count_rows(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}
