/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:03:01 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/07 14:38:39 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float dot_product(float v1[3], float v2[3]) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

void cross_product(float v1[3], float v2[3], float result[3]) {
    result[0] = v1[1] * v2[2] - v1[2] * v2[1];
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void normalize(float v[3]) {
    float length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (length != 0.0f) {
        v[0] /= length;
        v[1] /= length;
        v[2] /= length;
    }
}

float	**create_view_matrix(void)
{
	float	**matrix;
	int		i;

	matrix = (float **)malloc(4 * sizeof(float *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		matrix[i] = (float *)malloc(4 * sizeof(float));
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

float	**fill_view_matrix(t_camera *camera)
{
    float	forward[3];
	float	right[3];
	float	up[3];
	float	**view_matrix;

	view_matrix = create_view_matrix();
    // Calculate the forward vector (camera direction)
    forward[0] = camera->target_x - camera->pos_x;
    forward[1] = camera->target_y - camera->pos_y;
    forward[2] = camera->target_z - camera->pos_z;
    normalize(forward); // Normalize the forward vector

    // Calculate the right vector (cross product of forward and up)
    cross_product(forward, (float[]){camera->up_x, camera->up_y, camera->up_z}, right);
    normalize(right);

    // Recalculate the up vector (cross product of right and forward)
    cross_product(right, forward, up);
    normalize(up);

    // Build the view matrix
    view_matrix[0][0] = right[0];
    view_matrix[0][1] = right[1];
    view_matrix[0][2] = right[2];
    view_matrix[0][3] = -dot_product(right, (float[]){camera->pos_x, camera->pos_y, camera->pos_z});

    view_matrix[1][0] = up[0];
    view_matrix[1][1] = up[1];
    view_matrix[1][2] = up[2];
    view_matrix[1][3] = -dot_product(up, (float[]){camera->pos_x, camera->pos_y, camera->pos_z});

    view_matrix[2][0] = -forward[0];
    view_matrix[2][1] = -forward[1];
    view_matrix[2][2] = -forward[2];
    view_matrix[2][3] = dot_product(forward, (float[]){camera->pos_x, camera->pos_y, camera->pos_z});

    view_matrix[3][0] = 0.0f;
    view_matrix[3][1] = 0.0f;
    view_matrix[3][2] = 0.0f;
    view_matrix[3][3] = 1.0f;
	return (view_matrix);
}

t_3d_pt transform_point(float **view_matrix, t_3d_pt point)
{
    t_3d_pt transformed;

    transformed.x = view_matrix[0][0] * point.x + view_matrix[0][1] * point.y + view_matrix[0][2] * point.z + view_matrix[0][3];
    transformed.y = view_matrix[1][0] * point.x + view_matrix[1][1] * point.y + view_matrix[1][2] * point.z + view_matrix[1][3];
    transformed.z = view_matrix[2][0] * point.x + view_matrix[2][1] * point.y + view_matrix[2][2] * point.z + view_matrix[2][3];

    return transformed;
}