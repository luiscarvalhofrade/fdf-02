/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:54 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/12 16:31:07 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double	initial_scale(t_map *map)
{
	double	scale_x;
	double	scale_y;
	double	scale_factor;

	scale_x = SC_WIDTH / map->max_x;
	scale_y = SC_HEIGHT / map->max_y;
	scale_factor = min(scale_x, scale_y);
	if (scale_factor < 4)
		return (1);
	return (scale_factor / 3);
}
