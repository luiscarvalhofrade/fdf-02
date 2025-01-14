/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:28:44 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/13 21:28:45 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pt_n_ln(t_st_en_pts pts, t_fdf *fdf, int color)
{
	t_2d_pt	start;
	t_2d_pt	end;

	start = projection(pts.pt3d_start, fdf->proj);
	end = projection(pts.pt3d_end, fdf->proj);
	line_algo(fdf, start, end, color);
}

void	draw_all_pts_n_lns(t_map *map, t_fdf *fdf)
{
	int			y;
	int			x;
	t_st_en_pts	pts;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			pts.pt3d_start = def_st_pt(x, y, map->value_matrix);
			if (x + 1 < map->max_x)
			{
				pts.pt3d_end = def_end_x(x, y, map->value_matrix);
				draw_pt_n_ln(pts, fdf, map->color_matrix[y][x]);
			}
			if (y + 1 < map->max_y)
			{
				pts.pt3d_end = def_end_y(x, y, map->value_matrix);
				draw_pt_n_ln(pts, fdf, map->color_matrix[y][x]);
			}
			x++;
		}
		y++;
	}
}
