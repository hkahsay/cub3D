/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:14:21 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/10 12:13:22 by ckarl            ###   ########.fr       */
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
	ray->a_tan = -1/tan(game->ray_data.view_angle);
	// ray->deltaDist.x = get_delta_distance(ray->rayDir.x);
	// ray->deltaDist.y = get_delta_distance(ray->rayDir.y);
	// calculate_step_sideDist(ray);
}

// void	draw_ray(t_ray_data *ray_data, t_game *game)
// {
// 	int		flag;
// 	float	rx = 0, ry = 0, xstep = 0, ystep = 0;
// 	t_ray	copy;
// 	t_player_coord	grid;
// 	float	grid_to_screen;

// 	grid_to_screen = MAX_WIDTH / game->data->map_data.m_width;
// 	copy = ray_data->rays[0];
// 	init_ray_struct(&copy, game);

// 	grid.x = copy.player->pos.x;
// 	grid.y = copy.player->pos.y;
// 	flag = 0;

// 	if (ray_data->view_angle < M_PI && ray_data->view_angle > 0) // looking up
// 	{
// 		ry = (((int)grid.y>>6)<<6) - 0.0001;
// 		rx = (grid.y - ry) / tan(60) + grid.x;
// 		ystep = -64;
// 		xstep = -ystep / tan(60);
// 	}
// 	if (ray_data->view_angle > M_PI && ray_data->view_angle < (2 * M_PI)) // looking down
// 	{
// 		//code
// 	}
// 	if (ray_data->view_angle == 0 || ray_data->view_angle == M_PI || ray_data->view_angle == (2 * M_PI)) //looking directly right or left
// 	{
// 		//code
// 	}
// 	//check if wall is hit
// 	if (game->data->map_data.map[(int)ry]\
// 	[(int)rx] == '1')
// 	{
// 		printf("wall was hit after side step\n");
// 		return;
// 	}
// 	while (ry * grid_to_screen >= 0 && rx * grid_to_screen < MAX_WIDTH)
// 	{
// 		my_mlx_pixel_put(&game->img, rx * SCALE_GAME, ry * SCALE_GAME, 0x00FF0000);
// 		if (game->data->map_data.map[(int)ry]\
// 		[(int)rx] == '1')
// 		{
// 			printf("wall was hit after iteration %d\n", flag);
// 			return ;
// 		}
// 		ry += ystep;
// 		rx += xstep;
// 		flag++;
// 	}
// }