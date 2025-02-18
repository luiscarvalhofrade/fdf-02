/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:28:48 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/18 14:36:09 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_fdf(const char *filename)
{
	int	fd;

	if (!has_fdf_extension(filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!is_not_empty(fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (0);
	if (is_valid_fdf(argv[1]))
		write(1, "Valid .fdf file.\n", 17);
	else
	{
		write(1, "Problems with file!\n", 20);
		return (0);
	}
	map = create_map(argv[1]);
	render_map(map);
	return (0);
}
