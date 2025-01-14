/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:51 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/13 21:29:52 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d_pt	rotate_proj(t_2d_pt point, t_proj *proj)
{
	int	dx;
	int	dy;

	dx = point.x - SC_WIDTH / proj->width_factor;
	dy = point.y - SC_HEIGHT / proj->height_factor;
	point.x = dx * cos(proj->angle_y) - dy * \
		sin(proj->angle_y) + SC_WIDTH / proj->width_factor;
	point.y = dx * sin(proj->angle_y) + dy * \
		cos(proj->angle_y) + SC_HEIGHT / proj->height_factor;
	return (point);
}
