/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:20 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/10 17:45:12 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_scale(int keycode, t_fdf *fdf)
{
	if (keycode == PLUS_KEY)
		fdf->proj->scale += 1;
	else if (keycode == MINUS_KEY)
		fdf->proj->scale -= 1;
	re_render_img(fdf);
	return (0);
}

int	handle_translate_width(int keycode, t_fdf *fdf)
{
	if (keycode == RIGHT_KEY)
		fdf->proj->width_factor -= 0.2;
	else if (keycode == LEFT_KEY)
		fdf->proj->width_factor += 0.2;
	re_render_img(fdf);
	return (0);
}

int	handle_translate_height(int keycode, t_fdf *fdf)
{
	if (keycode == UP_KEY)
		fdf->proj->height_factor += 0.2;
	else if (keycode == DOWN_KEY)
		fdf->proj->height_factor -= 0.2;
	re_render_img(fdf);
	return (0);
}

int	handle_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == F1_KEY)
		fdf->proj->angle += 0.1;
	else if (keycode == F2_KEY)
		fdf->proj->angle -= 0.1;
	re_render_img(fdf);
	return (0);
}

int	handle_scale_z(int keycode, t_fdf *fdf)
{
	if (keycode == F3_KEY)
		fdf->proj->z_scale -= 0.1;
	else if (keycode == F4_KEY)
		fdf->proj->z_scale += 0.1;
	re_render_img(fdf);
	return (0);
}
