/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:13 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/14 10:46:10 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->value_matrix = NULL;
	map->color_matrix = NULL;
	map->max_x = 0;
	map->max_y = 0;
	return (map);
}

static t_img	*init_img(void *mlx, int sc_width, int sc_height)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx, sc_width, sc_height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
			&img->line_len, &img->endian);
	return (img);
}

static t_proj	*init_proj(t_map *map)
{
	t_proj	*projection;

	projection = (t_proj *)malloc(sizeof(t_proj));
	if (!projection)
		return (NULL);
	projection->angle = 0.0;
	projection->scale = initial_scale(map);
	projection->z_scale = 1;
	projection->move_x = SC_WIDTH / 2;
	projection->move_y = SC_HEIGHT / 2;
	return (projection);
}

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->sc_width = SC_WIDTH;
	fdf->sc_height = SC_HEIGHT;
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->sc_width, \
		fdf->sc_height, "FdF");
	fdf->img = init_img(fdf->mlx, fdf->sc_width, fdf->sc_height);
	fdf->map = map;
	fdf->proj = init_proj(map);
	return (fdf);
}
