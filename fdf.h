/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:28:53 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/10 17:24:48 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SC_WIDTH 1024
# define SC_HEIGHT 768
# define COLOR_DEFAULT 0x00FF00
# define BUFFER_SIZE 100

# include "keys.h"
# include "structs.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"

char	*get_next_line(int fd);
char	**ft_free_split(char **result, int i);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);

int		ft_found_new_line(t_list *list);
int		ft_len_of_new_line(t_list *list);
int		ft_count_items(const char *s, char c);
int		ft_atoi(const char *nptr);
int		ft_atoi_base(char *nptr, int base);
int		centralize_width(void);
int		centralize_height(void);
int		initial_scale(void);

int		is_valid_map(char *file);
int		*fill_line_value(int **matrix, char **result, int y, int max_x);
int		*fill_line_color(int **matrix, char **result, int y, int max_x);
int		**create_matrix(t_map *map);
int		render_map(t_map *map);

int		handle_scale(int keycode, t_fdf *fdf);
int		handle_translate_width(int keycode, t_fdf *fdf);
int		handle_translate_height(int keycode, t_fdf *fdf);
int		handle_rotation(int keycode, t_fdf *fdf);
int		handle_scale_z(int keycode, t_fdf *fdf);

t_map	*init_map(void);
t_map	*create_map(char *file);

t_2d_pt	projection(t_3d_pt point, t_proj *proj);
t_2d_pt	rotate_proj(t_2d_pt point, t_proj *proj);
t_2d_pt	projection(t_3d_pt point, t_proj *proj);

t_3d_pt	def_st_pt(int x, int y, int **matrix);
t_3d_pt	def_end_x(int x, int y, int **matrix);
t_3d_pt	def_end_y(int x, int y, int **matrix);
t_3d_pt transform_point(float **view_matrix, t_3d_pt point);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_copy_string(t_list *list, char *str);
void	ft_free(t_list **list, t_list *clean_node, char *buffer);
void	line_algo(t_fdf *fdf, t_2d_pt start, t_2d_pt end, int color);
void	draw_all_pts_n_lns(t_map *map, t_fdf *fdf);
void	free_structs(t_fdf *fdf);
void	re_render_img(t_fdf *fdf);
void	close_reaction(t_fdf *fdf);
void    get_max_min_x_y_values(t_fdf *fdf, t_2d_pt point);

float	**fill_view_matrix(t_camera *camera);

t_fdf	*init_fdf(t_map *map);

t_proj	*init_proj(void);

t_img	*init_img(void *mlx, int sc_width, int sc_height);

t_list	*ft_find_last_node(t_list *list);

#endif