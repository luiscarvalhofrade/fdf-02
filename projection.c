/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:34 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/14 12:57:32 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	projected.x = (int)((point.x - point.y) * cos(M_PI / 6));
	projected.y = (int)((point.x + point.y) * sin(M_PI / 6) - point.z);
	return (projected);
}

t_2d_pt	translate_proj(t_2d_pt point, t_proj *proj)
{
	point.x += SC_WIDTH / proj->width_factor;
	point.y += SC_HEIGHT / proj->height_factor;
	return (point);
}

t_2d_pt	projection(t_3d_pt point, t_proj *proj)
{
	t_2d_pt	converted;

	point = scale_proj(point, proj);
	point = scale_z(point, proj);
	converted = isometric_proj(point);
	converted = rotate_proj(converted, proj);
	converted = translate_proj(converted, proj);
	return (converted);
}
