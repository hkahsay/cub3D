/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:14:21 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/13 17:36:01 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_rays(t_game *game)
{
	// game->ray_data.rays = malloc(sizeof(t_ray) * MAX_WIDTH);
	// if (!game->ray_data.rays)
	// {
	// 	printf("Error\nMalloc failed\n");
	// 	exit(EXIT_SUCCESS);
	// }
	//initiate each ray by 1. calculating first intersection (is ray facing up or down, left or right?),
	//2. then increase until 3. wall is hit, 3. distance and 4. draw line
	game->ray_data.view_angle = angle_to_rad(60);
	game->ray_data.dist_to_plane = (MAX_WIDTH / 2) \
				/ tan(game->ray_data.view_angle / 2);
	game->ray_data.sub_ray_angle = angle_to_rad(FOV_ANGLE / MAX_WIDTH);
}

void	init_ray_struct(t_ray *ray, t_game *game)
{
	// ray->player = &(game->player);
	ray->ray_pos.x = cos(game->ray_data.view_angle);
	ray->ray_pos.y = sin(game->ray_data.view_angle);
	// ray->deltaDist.x = get_delta_distance(ray->rayDir.x);
	// ray->deltaDist.y = get_delta_distance(ray->rayDir.y);
	// calculate_step_sideDist(ray);
}

void	set_ray_coef(t_ray *ray)
{
	if (ray->player.dir_field == N_E)
	{
		ray->coef.x = -1;
		ray->coef.y = -1;
	}
	else if (ray->player.dir_field == N_W)
	{
		ray->coef.x = 1;
		ray->coef.y = -1;
	}
	else if (ray->player.dir_field == S_W)
	{
		ray->coef.x = -1;
		ray->coef.y = 1;
	}
	else if (ray->player.dir_field == S_E)
	{
		ray->coef.x = 1;
		ray->coef.y = 1;
	}
	else if (ray->player.dir_field == N)
		ray->coef.x = 0;
	else if (ray->player.dir_field == W)
		ray->coef.x = -1;
	else if (ray->player.dir_field == S)
		ray->coef.x = 0;
	else if (ray->player.dir_field == E)
		ray->coef.x = 1;
}

void	draw_ray(t_game *game)

{
	t_ray	ray;

	ray.ray_pos = game->player.pos;
	ray.player.dir = game->player.dir + (M_PI / 6);
	if (ray.player.dir > 2 * M_PI)
		ray.player.dir -= 2 * M_PI;
	if (ray.player.dir < 0)
		ray.player.dir += 2 * M_PI;
	check_direction(&ray.player);
	beta_angle_calc(&ray.player);
	set_ray_coef(&ray);
	ray.sidedist.y = (int)(ray.ray_pos.y + ray.coef.y);
	if (ray.player.dir_field == S_W || ray.player.dir_field == N_E)
		ray.sidedist.x = ray.ray_pos.x + ray.coef.x * \
		((ray.sidedist.y - ray.ray_pos.y) * tan(ray.player.beta));
	else if (ray.player.dir_field == S_E || ray.player.dir_field == N_W)
		ray.sidedist.x = ray.ray_pos.x + ray.coef.x * \
		((ray.sidedist.y - ray.ray_pos.y) / tan(ray.player.beta));
	else
		ray.sidedist.x = (int)ray.ray_pos.x + ray.coef.x;
	my_mlx_pixel_put(&game->img, ray.sidedist.x * SCALE_MINI_MAP, ray.sidedist.y * SCALE_MINI_MAP, 0x0000FF00);
	// printf("distance x %f and y %f\n", ray.sidedist.x, ray.sidedist.y);
}
