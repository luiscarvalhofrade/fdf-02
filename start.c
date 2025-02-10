/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:54 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/10 17:07:20 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void get_max_min_x_y_values(t_fdf *fdf, t_2d_pt point)
{
    // Update min and max x values
    if (point.x < fdf->proj->max_d_x)
        fdf->proj->min_d_x = point.x;
    if (point.x > fdf->proj->min_d_x)
        fdf->proj->max_d_x = point.x;

    // Update min and max y values
    if (point.y < fdf->proj->max_d_y)
        fdf->proj->min_d_y = point.y;
    if (point.y > fdf->proj->min_d_y)
	{
        fdf->proj->max_d_y = point.y;
	}
	printf("max x:%d, min x:%d\n", fdf->proj->max_d_x, fdf->proj->min_d_x);
	printf("max y:%d, min y:%d\n", fdf->proj->max_d_y, fdf->proj->min_d_y);
}

int	centralize_width(void)
{
	int	width_factor;

	width_factor = 1;
	return (width_factor);
}

int	centralize_height(void)
{
	int	height_factor;

	height_factor = 1;
	return (height_factor);
}

int	initial_scale(void)
{
	int	scale;

	scale = 10;
	return (scale);
}
