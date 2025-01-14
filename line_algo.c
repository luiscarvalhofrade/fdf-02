/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:29 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/13 21:29:29 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line_algo	define_sx_sy(t_2d_pt start, t_2d_pt end)
{
	t_line_algo	bre_eq;

	bre_eq.dx = abs(end.x - start.x);
	bre_eq.dy = abs(end.y - start.y);
	if (start.x < end.x)
		bre_eq.sx = 1;
	else
		bre_eq.sx = -1;
	if (start.y < end.y)
		bre_eq.sy = 1;
	else
		bre_eq.sy = -1;
	return (bre_eq);
}

void	line_algo(t_fdf *fdf, t_2d_pt start, t_2d_pt end, int color)
{
	t_line_algo	bre_eq;

	bre_eq = define_sx_sy(start, end);
	bre_eq.err = bre_eq.dx - bre_eq.dy;
	while (1)
	{
		my_mlx_pixel_put(fdf->img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		bre_eq.e2 = 2 * bre_eq.err;
		if (bre_eq.e2 > -bre_eq.dy)
		{
			bre_eq.err -= bre_eq.dy;
			start.x += bre_eq.sx;
		}
		if (bre_eq.e2 < bre_eq.dx)
		{
			bre_eq.err += bre_eq.dx;
			start.y += bre_eq.sy;
		}
	}
}
