/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:54 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/13 21:58:13 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	centralize_width(t_map *map)
{
	int	width_factor;

	width_factor = map->max_x / 2;
	return (width_factor);
}

int	centralize_height(t_map *map)
{
	int	height_factor;

	height_factor = map->max_y / 2;
	return (height_factor);
}

int	initial_scale(void)
{
	int	scale;

	scale = 10;
	return (scale);
}
