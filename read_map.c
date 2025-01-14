/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:47 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/13 21:29:48 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_max_y(char *file)
{
	int		fd;
	int		max_y;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	max_y = 0;
	while (line)
	{
		max_y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (max_y);
}

int	get_max_x(char *file)
{
	int		fd;
	int		max_x;
	char	*line;

	max_x = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		max_x = ft_count_items(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (max_x);
}

int	**get_value_matrix(char *file, t_map *map, int **matrix)
{
	int		fd;
	int		y;
	char	*line;
	char	**result;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
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
		return (NULL);
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
	if (is_valid_map(file) == 1)
	{
		free(map);
		return (NULL);
	}
	map->max_y = get_max_y(file);
	map->max_x = get_max_x(file);
	value_matrix = create_matrix(map);
	color_matrix = create_matrix(map);
	map->value_matrix = get_value_matrix(file, map, value_matrix);
	map->color_matrix = get_color_matrix(file, map, color_matrix);
	return (map);
}
