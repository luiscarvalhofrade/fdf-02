/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:28:38 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/13 21:28:39 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d_pt	def_st_pt(int x, int y, int **matrix)
{
	t_3d_pt	point3d_start;

	point3d_start.x = x;
	point3d_start.y = y;
	point3d_start.z = matrix[y][x];
	return (point3d_start);
}

t_3d_pt	def_end_x(int x, int y, int **matrix)
{
	t_3d_pt	point3d_end;

	point3d_end.x = x + 1;
	point3d_end.y = y;
	point3d_end.z = matrix[y][x + 1];
	return (point3d_end);
}

t_3d_pt	def_end_y(int x, int y, int **matrix)
{
	t_3d_pt	point3d_end;

	point3d_end.x = x;
	point3d_end.y = y + 1;
	point3d_end.z = matrix[y + 1][x];
	return (point3d_end);
}
