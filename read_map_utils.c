/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:43 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/12 18:58:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_map(char *file)
{
	int		fd;
	int		max_x;
	int		previous_x;
	char	*line;

	max_x = 0;
	previous_x = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	previous_x = ft_count_items(line, ' ');
	while (line)
	{
		max_x = ft_count_items(line, ' ');
		if (previous_x != max_x)
			return (1);
		free(line);
		line = get_next_line(fd);
		previous_x = max_x;
	}
	free(line);
	close(fd);
	return (0);
}

int	save_point(char *pt)
{
	char	**info;
	int		value_z;

	value_z = 0;
	if (ft_strchr(pt, ','))
	{
		info = ft_split(pt, ',');
		value_z = ft_atoi(info[0]);
		free(info[0]);
		free(info[1]);
		free(info);
	}
	else
		value_z = ft_atoi(pt);
	return (value_z);
}

int	save_color(char *pt)
{
	char	**info;
	int		color_value;

	color_value = 0;
	if (ft_strchr(pt, ','))
	{
		info = ft_split(pt, ',');
		color_value = ft_atoi_hex(info[1]);
		free(info[0]);
		free(info[1]);
		free(info);
	}
	else
		color_value = COLOR_DEFAULT;
	return (color_value);
}

int	*fill_line_value(int **matrix, char **result, int y, int max_x)
{
	int	x;

	x = 0;
	while (x < max_x)
	{
		matrix[y][x] = save_point(result[x]);
		x++;
	}
	return (matrix[y]);
}

int	*fill_line_color(int **matrix, char **result, int y, int max_x)
{
	int	x;

	x = 0;
	while (x < max_x)
	{
		matrix[y][x] = save_color(result[x]);
		x++;
	}
	return (matrix[y]);
}
