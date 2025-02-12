/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_max_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:40:27 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/12 18:38:24 by luide-ca         ###   ########.fr       */
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
