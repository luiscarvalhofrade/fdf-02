/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:47 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/14 10:35:05 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**get_value_matrix(char *file, t_map *map, int **matrix)
{
	int		fd;
	int		y;
	char	*line;
	char	**result;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	y = 0;
	while (y < map->max_y)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result = ft_split(line, ' ');
		matrix[y] = fill_line_value(matrix, result, y, map->max_x);
		ft_free_split(result, map->max_x);
		free(line);
		y++;
	}
	close(fd);
	return (matrix);
}

int	**get_color_matrix(char *file, t_map *map, int **matrix)
{
	int		fd;
	int		y;
	char	*line;
	char	**result;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	y = 0;
	while (y < map->max_y)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result = ft_split(line, ' ');
		matrix[y] = fill_line_color(matrix, result, y, map->max_x);
		ft_free_split(result, map->max_x);
		free(line);
		y++;
	}
	close(fd);
	return (matrix);
}

t_map	*create_map(char *file)
{
	t_map	*map;
	int		**value_matrix;
	int		**color_matrix;

	map = init_map();
	if (is_valid_map(file) == 0)
	{
		free(map);
		exit(1);
	}
	map->max_y = get_max_y(file);
	map->max_x = get_max_x(file);
	value_matrix = create_matrix(map);
	color_matrix = create_matrix(map);
	map->value_matrix = get_value_matrix(file, map, value_matrix);
	map->color_matrix = get_color_matrix(file, map, color_matrix);
	return (map);
}
