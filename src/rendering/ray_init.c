/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:14:21 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/18 15:04:06 by ckarl            ###   ########.fr       */
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
	game->ray_data.view_angle = angle_to_rad((double)FOV_ANGLE);
	game->ray_data.dist_to_plane = (double)(MAX_WIDTH / 2.00) \
				/ tan(game->ray_data.view_angle / 2.00);
	game->ray_data.sub_ray_angle = angle_to_rad((double)FOV_ANGLE \
				/ (double)MAX_WIDTH);
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

void	draw_all_rays(t_game *game)
{
	t_ray	*rays;
	double	ray_angle;
	int		i;

	ray_angle = game->player.dir + (M_PI / 6);
	if (ray_angle > 2 * M_PI)
		ray_angle -= 2 * M_PI;
	rays = malloc(sizeof(t_ray) * MAX_WIDTH);
	if (!rays)
		return ;								//add error msg
	i = -1;
	while (++i < MAX_WIDTH)
	{
		rays[i].ray_pos = game->player.pos;
		rays[i].player.dir = ray_angle;
		draw_single_ray(&rays[i], game);
		ray_angle -= game->ray_data.sub_ray_angle;
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
	}
	free(rays);
}

void	get_wall_height(t_ray *ray, t_game *game, double distance)
{
	if (game->player.dir < ray->player.dir)
	{
		if ((game->player.dir_field == N_E || game->player.dir_field == E) \
		&& ray->player.dir_field == S_E)
			ray->perpwallangle = M_PI - (game->player.dir + 2 * M_PI - \
			ray->player.dir);
		else
			ray->perpwallangle = M_PI - (ray->player.dir - game->player.dir);
	}
	else
	{
		if ((game->player.dir_field == S_E || game->player.dir_field == E) \
		&& ray->player.dir_field == N_E)
			ray->perpwallangle = M_PI - (ray->player.dir + 2 * M_PI - \
			game->player.dir);
		else
			ray->perpwallangle = M_PI - (game->player.dir - ray->player.dir);
	}
	ray->perpwalldist = fabs(distance * sin(ray->perpwallangle));
	// ray->wallheight = ;
}

void	draw_single_ray(t_ray *ray, t_game *game)
{
	check_direction(&ray->player);
	beta_angle_calc(&ray->player);
	get_horizontal_ray(ray, game);
	get_vertical_ray(ray, game);
	if (ray->eucl_dist.hz < ray->eucl_dist.vt)
	{
		printf("hz is smaller\n");
		get_wall_height(ray, game, ray->eucl_dist.hz);
		if (check_north(ray->player.dir) == 1)
			ray->texture = &game->data->south_texture;
		else
			ray->texture = &game->data->north_texture;
	}
	else
	{
		printf("vt is smaller\n");
		get_wall_height(ray, game, ray->eucl_dist.vt);
		if (check_west(ray->player.dir) == 1)
			ray->texture = &game->data->east_texture;
		else
			ray->texture = &game->data->west_texture;
	}
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
