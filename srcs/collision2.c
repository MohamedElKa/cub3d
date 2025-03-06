/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:56:59 by mel-karm          #+#    #+#             */
/*   Updated: 2023/10/17 14:06:49 by mel-karm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	cast_col(t_mlx *mlx)
{
	double	d_h;
	double	d_v;
	double	raydistance;

	mlx->rays.angle_c = normalize_angle(mlx->player.rotationangle);
	horizontal_intersections_c(mlx);
	vertical_intersections_c(mlx);
	d_h = distance_h(mlx);
	d_v = distance_v(mlx);
	if (d_h >= d_v)
		raydistance = d_v;
	else
		raydistance = d_h;
	return (raydistance);
}
