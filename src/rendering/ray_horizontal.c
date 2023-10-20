/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:50:58 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/20 12:05:56 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (check_north(ray->player.dir) == 1)
		{
			if (check_map_error(ray->ray_pos.x, ray->ray_pos.y - 1, game) == 1)
				break ;
		}
		if (game->data->mini_map == 1)
			my_mlx_pixel_put(&game->img, (ray->ray_pos.x) * SCALE_MINI_MAP, \
				(ray->ray_pos.y) * SCALE_MINI_MAP, 0x00FF0000);
		ray->ray_pos.x += ray->deltadist.x;
		ray->ray_pos.y += ray->deltadist.y;
		ray->eucl_dist.hz += hypot(ray->deltadist.x, ray->deltadist.y);
	}
	ray->ray_pos = position;
}

//get side distance for horizontal
void	get_sidedist_hz(t_ray *ray)
{
	if (check_north(ray->player.dir) == 1)
		ray->sidedist.y = ((int)ray->ray_pos.y) - ray->ray_pos.y;
	else
		ray->sidedist.y = ((int)(ray->ray_pos.y + 1)) - ray->ray_pos.y;
	if (ray->player.dir_field == S_W || ray->player.dir_field == N_E)
		ray->sidedist.x = -1 * ray->sidedist.y * tan(ray->player.beta);
	else if (ray->player.dir_field == S_E || ray->player.dir_field == N_W)
		ray->sidedist.x = ray->sidedist.y / tan(ray->player.beta);
	else
		ray->sidedist.x = (int)ray->coef.x;
	ray->eucl_dist.hz = hypot(ray->sidedist.y, ray->sidedist.x);
}

//get delta distance for horizontal
void	get_deltadist_hz(t_ray *ray)
{
	ray->deltadist.y = ray->coef.y;
	if (ray->player.dir_field == S_W || ray->player.dir_field == N_E)
		ray->deltadist.x = -1 * ray->deltadist.y * tan(ray->player.beta);
	else if (ray->player.dir_field == S_E || ray->player.dir_field == N_W)
		ray->deltadist.x = ray->deltadist.y / tan(ray->player.beta);
	else
		ray->deltadist.x = ray->coef.x;
}

//for horizontal RC
void	set_ray_coef_hz(t_ray *ray)
{
	ray->coef.y = -1;
	ray->coef.x = 1;
	if (ray->player.dir_field == N_E)
		ray->coef.x = -1;
	else if (ray->player.dir_field == S_W)
	{
		ray->coef.x = -1;
		ray->coef.y = 1;
	}
	else if (ray->player.dir_field == S_E)
		ray->coef.y = 1;
	else if (ray->player.dir_field == N)
		ray->coef.x = 0;
	else if (ray->player.dir_field == W)
		ray->coef.x = -1;
	else if (ray->player.dir_field == S)
		ray->coef.x = 0;
	else if (ray->player.dir_field == E)
		ray->coef.x = 1;
}
