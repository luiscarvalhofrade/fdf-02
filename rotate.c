/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:51 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/06 17:59:03 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
