/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:34 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/12 16:35:17 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d_pt	center_to_origin(t_3d_pt point, t_map *map)
{
	point.x -= map->max_x / 2;
	point.y -= map->max_y / 2;
	return (point);
}

t_3d_pt	scale_proj(t_3d_pt point, t_proj *proj)
{
	point.x = point.x * proj->scale;
	point.y = point.y * proj->scale;
	point.z = point.z * proj->scale;
	return (point);
}

t_3d_pt	scale_z(t_3d_pt point, t_proj *proj)
{
	point.z = point.z * proj->z_scale;
	return (point);
}

t_2d_pt	isometric_proj(t_3d_pt point)
{
	t_2d_pt	projected;

	projected.x = (int)((point.x - point.y) * cos(PI / 6));
	projected.y = (int)((point.x + point.y) * sin(PI / 6) - point.z);
	return (projected);
}

t_2d_pt	translate_proj(t_2d_pt point, t_proj *proj)
{
	point.x += proj->move_x;
	point.y += proj->move_y;
	return (point);
}

t_2d_pt	projection(t_3d_pt point, t_fdf *fdf)
{
	t_2d_pt	converted;

	point = center_to_origin(point, fdf->map);
	point = scale_proj(point, fdf->proj);
	point = scale_z(point, fdf->proj);
	converted = isometric_proj(point);
	converted = rotate_proj(converted, fdf->proj);
	converted = translate_proj(converted, fdf->proj);
	return (converted);
}
