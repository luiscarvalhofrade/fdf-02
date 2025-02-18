/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:30:06 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/18 14:38:40 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	has_fdf_extension(const char *filename)
{
	const char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ext && ft_strcmp(ext, ".fdf") == 0)
		return (1);
	else
		return (0);
}

int	is_not_empty(int fd)
{
	char	buffer[1];

	if (read(fd, buffer, 1) > 0)
		return (1);
	else
		return (0);
}
