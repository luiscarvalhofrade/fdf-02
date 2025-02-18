/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:28:12 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/14 10:43:01 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	re_render_img(t_fdf *fdf)
{
	if (fdf->img->img)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	fdf->img->img = mlx_new_image(fdf->mlx, SC_WIDTH, SC_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp, \
			&fdf->img->line_len, &fdf->img->endian);
	draw_all_pts_n_lns(fdf->map, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img->img, 0, 0);
}

void	free_matrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	free_structs(t_fdf *fdf)
{
	free_matrix(fdf->map->color_matrix, fdf->map->max_y);
	free_matrix(fdf->map->value_matrix, fdf->map->max_y);
	free(fdf->map);
	free(fdf->proj);
	free(fdf->img);
}

void	close_reaction(t_fdf *fdf)
{
	if (fdf->img->img)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	if (fdf->mlx_win)
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	if (fdf->map && fdf->proj)
		free_structs(fdf);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
}
