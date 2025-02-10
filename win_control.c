/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:30:02 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/10 16:12:46 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_close(t_fdf *fdf)
{
	close_reaction(fdf);
	free(fdf);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
	{
		close_reaction(fdf);
		free(fdf);
		exit(0);
		return (0);
	}
	else if (keycode == F1_KEY || keycode == F2_KEY)
		handle_rotation(keycode, fdf);
	else if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		handle_scale(keycode, fdf);
	else if (keycode == RIGHT_KEY || keycode == LEFT_KEY)
		handle_translate_width(keycode, fdf);
	else if (keycode == UP_KEY || keycode == DOWN_KEY)
		handle_translate_height(keycode, fdf);
	else if (keycode == F3_KEY || keycode == F4_KEY)
		handle_scale_z(keycode, fdf);
	return (0);
}

int	render_map(t_map *map)
{
	t_fdf	*fdf;

	fdf = init_fdf(map);
	draw_all_pts_n_lns(fdf->map, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img->img, 0, 0);
	mlx_hook(fdf->mlx_win, 2, 1L << 0, handle_keypress, fdf);
	mlx_hook(fdf->mlx_win, 17, 0L, handle_close, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
