/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:14:21 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/17 18:32:30 by ckarl            ###   ########.fr       */
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

void	get_vertical_ray(t_ray *ray, t_game *game)
{
	set_ray_coef_vt(ray);
	get_sidedist_vt(ray);
	get_deltadist_vt(ray);
	ray->ray_pos.x += ray->sidedist.x;
	ray->ray_pos.y += ray->sidedist.y;
	while (check_map_error(ray->ray_pos.x, ray->ray_pos.y, game) == 0)
	{
		my_mlx_pixel_put(&game->img, (ray->ray_pos.x) * SCALE_MINI_MAP, \
		(ray->ray_pos.y) * SCALE_MINI_MAP, 0x0000FF00);
		ray->ray_pos.x += ray->deltadist.x;
		ray->ray_pos.y += ray->deltadist.y;
		ray->eucl_dist.vt += hypot(ray->deltadist.x, ray->deltadist.y);
	}
}

void	get_horizontal_ray(t_ray *ray, t_game *game)
{
	t_coord	position;

	position = ray->ray_pos;
	set_ray_coef_hz(ray);
	get_sidedist_hz(ray);
	get_deltadist_hz(ray);
	ray->ray_pos.x += ray->sidedist.x;
	ray->ray_pos.y += ray->sidedist.y;
	while (check_map_error(ray->ray_pos.x, ray->ray_pos.y, game) == 0)
	{
		my_mlx_pixel_put(&game->img, (ray->ray_pos.x) * SCALE_MINI_MAP, \
		(ray->ray_pos.y) * SCALE_MINI_MAP, 0x00FF0000);
		ray->ray_pos.x += ray->deltadist.x;
		ray->ray_pos.y += ray->deltadist.y;
		ray->eucl_dist.hz += hypot(ray->deltadist.x, ray->deltadist.y);
	}
	ray->ray_pos = position;
}

void	draw_ray(t_game *game)
{
	t_ray	ray;

	ray.ray_pos = game->player.pos;
	ray.player.dir = game->player.dir + (M_PI / 6);
	if (ray.player.dir > 2 * M_PI)
		ray.player.dir -= 2 * M_PI;
	check_direction(&ray.player);
	beta_angle_calc(&ray.player);
	get_horizontal_ray(&ray, game);
	get_vertical_ray(&ray, game);
	if (ray.eucl_dist.hz > ray.eucl_dist.vt)
		printf("hz is bigger\n");		//need to control if wall is hit for vertical west & horizontal north
	else
		printf("vt is bigger\n");
}

//check if coordinates are outside of map or hit a wall
//0 = all clear, 1 = wall, 2 = outside of map
int	check_map_error(double x, double y, t_game *game)
{
	t_map	map_data;

	map_data = game->data->map_data;
	if ((int)x < 0 || (int)x >= map_data.m_width || \
		(int)y < 0 || (int)y >= map_data.m_height)
		return (2);
	else if (map_data.map[(int)y] \
	[(int)x] != '0')
		return (1);
	return (0);
}
