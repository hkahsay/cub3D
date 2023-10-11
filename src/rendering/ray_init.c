/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:14:21 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/11 17:59:58 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_rays(t_game *game)
{
	game->ray_data.rays = malloc(sizeof(t_ray) * MAX_WIDTH);
	if (!game->ray_data.rays)
	{
		printf("Error\nMalloc failed\n");
		exit(EXIT_SUCCESS);
	}
	//initiate each ray by 1. calculating first intersection (is ray facing up or down, left or right?),
	//2. then increase until 3. wall is hit, 3. distance and 4. draw line
	game->ray_data.view_angle = angle_to_rad(60);
	game->ray_data.dist_to_plane = (MAX_WIDTH / 2) \
				/ tan(game->ray_data.view_angle / 2);
	game->ray_data.sub_ray_angle = angle_to_rad(FOV_ANGLE / MAX_WIDTH);
}

void	init_ray_struct(t_ray *ray, t_game *game)
{
	ray->player = &(game->player);
	ray->rayDir.x = cos(game->ray_data.view_angle);
	ray->rayDir.y = sin(game->ray_data.view_angle);
	// ray->deltaDist.x = get_delta_distance(ray->rayDir.x);
	// ray->deltaDist.y = get_delta_distance(ray->rayDir.y);
	// calculate_step_sideDist(ray);
}

// void	draw_ray(t_ray_data *ray_data, t_game *game)

// {


// }
