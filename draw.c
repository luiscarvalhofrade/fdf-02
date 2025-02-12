/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:28:44 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/12 15:47:01 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SC_WIDTH || y < 0 || y >= SC_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_pt_n_ln(t_st_en_pts pts, t_fdf *fdf, int color)
{
	t_2d_pt	start;
	t_2d_pt	end;

	start = projection(pts.pt3d_start, fdf);
	end = projection(pts.pt3d_end, fdf);
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
