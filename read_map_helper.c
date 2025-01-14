/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:39 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/13 21:29:40 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**create_matrix(t_map *map)
{
	int				**matrix;
	int				i;

	if (map->max_y == 0 || map->max_x == 0)
		return (NULL);
	matrix = (int **)malloc(map->max_y * sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < map->max_y)
	{
		matrix[i] = (int *)malloc(map->max_x * sizeof(int));
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}
