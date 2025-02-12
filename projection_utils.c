/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:51 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/12 18:52:30 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d_pt	center_to_origin(t_3d_pt point, t_map *map)
{
	point.x -= map->max_x / 2;
	point.y -= map->max_y / 2;
	return (point);
}

t_2d_pt	rotate_proj(t_2d_pt point, t_proj *proj)
{
	int	dx;
	int	dy;

	dx = point.x;
	dy = point.y;
	point.x = dx * cos(proj->angle) - dy * sin(proj->angle);
	point.y = dx * sin(proj->angle) + dy * cos(proj->angle);
	return (point);
}
