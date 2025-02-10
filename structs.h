/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:58 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/07 19:00:07 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_camera
{
    float	pos_x;
	float	pos_y;
	float	pos_z;
    float	target_x; 
	float	target_y; 
	float	target_z;
    float	up_x;
	float	up_y;
	float	up_z;
}			t_camera;

typedef struct s_start_pos
{
	int		scale;
	double	height_factor;
}			t_start_pos;

typedef struct s_map
{
	int	**value_matrix;
	int	**color_matrix;
	int	max_x;
	int	max_y;
}		t_map;

typedef struct s_pt_3d
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_pt_3d;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_proj
{
	double		angle;
	int			scale;
	int			max_d_x;
	int			max_d_y;
	int			min_d_x;
	int			min_d_y;
	int			map_center_x;
	int			map_center_y;
	double		width_factor;
	double		height_factor;
	double		z_scale;
	t_camera	*camera;
}			t_proj;

typedef struct s_fdf
{
	void	*mlx;
	void	*mlx_win;
	int		sc_width;
	int		sc_height;
	t_img	*img;
	t_map	*map;
	t_proj	*proj;
}			t_fdf;

typedef struct s_line_algo
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}		t_line_algo;

typedef struct s_list
{
	char			*content;
	struct s_list	*next_node;
}					t_list;

typedef struct s_3d_pt
{
	int	x;
	int	y;
	int	z;
}	t_3d_pt;

typedef struct s_2d_pt
{
	int	x;
	int	y;
}	t_2d_pt;

typedef struct s_st_en_pts
{
	t_3d_pt	pt3d_start;
	t_3d_pt	pt3d_end;
}			t_st_en_pts;

#endif