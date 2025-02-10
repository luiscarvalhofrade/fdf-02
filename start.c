/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:54 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/10 18:07:05 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	centralize_width(void)
{
	int	width_factor;

	width_factor = 1;
	return (width_factor);
}

int	centralize_height(t_map *map)
{
	int	height_factor;

	if (map->max_y < 100)
		height_factor = 2;
	else if (map->max_y > 100 && map->max_y <=400)
		height_factor = 3;
	else
		height_factor = 4;
	return (height_factor);
}

int	initial_scale(t_map *map)
{
	int	scale;

	if (map->max_y < 100)
		scale = 20;
	else if (map->max_y > 100 && map->max_y <=400)
		scale = 10;
	else
		scale = 1;
	return (scale);
}
