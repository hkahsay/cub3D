/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:50:16 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/18 16:25:25 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_vertical_ray(t_ray *ray, t_game *game)
{
	set_ray_coef_vt(ray);
	get_sidedist_vt(ray);
	get_deltadist_vt(ray);
	ray->ray_pos.x += ray->sidedist.x;
	ray->ray_pos.y += ray->sidedist.y;
	while (check_map_error(ray->ray_pos.x, ray->ray_pos.y, game) == 0)
	{
		if (check_west(ray->player.dir) == 1)
		{
			if (check_map_error(ray->ray_pos.x - 1, ray->ray_pos.y, game) != 0)
				break ;
		}
		// my_mlx_pixel_put(&game->img, (ray->ray_pos.x) * SCALE_MINI_MAP, \
		// (ray->ray_pos.y) * SCALE_MINI_MAP, 0x0000FF00);
		ray->ray_pos.x += ray->deltadist.x;
		ray->ray_pos.y += ray->deltadist.y;
		ray->eucl_dist.vt += hypot(ray->deltadist.x, ray->deltadist.y);
	}
}

//get side distance for vertical
void	get_sidedist_vt(t_ray *ray)
{
	if (check_west(ray->player.dir) == 1)
		ray->sidedist.x = ((int)ray->ray_pos.x) - ray->ray_pos.x;
	else
		ray->sidedist.x = ((int)(ray->ray_pos.x + 1)) - ray->ray_pos.x;
	if (ray->player.dir_field == S_W || ray->player.dir_field == N_E)
		ray->sidedist.y = -1 * (ray->sidedist.x / tan(ray->player.beta));
	else if (ray->player.dir_field == S_E || ray->player.dir_field == N_W)
		ray->sidedist.y = ray->sidedist.x * tan(ray->player.beta);
	else
		ray->sidedist.y = (int)ray->coef.y;
	ray->eucl_dist.vt = hypot(ray->sidedist.y, ray->sidedist.x);
}

//get delta distance for vertical
void	get_deltadist_vt(t_ray *ray)
{
	ray->deltadist.x = ray->coef.x;
	if (ray->player.dir_field == S_W || ray->player.dir_field == N_E)
		ray->deltadist.y = -1 * (ray->deltadist.x / tan(ray->player.beta));
	else if (ray->player.dir_field == S_E || ray->player.dir_field == N_W)
		ray->deltadist.y = ray->deltadist.x * tan(ray->player.beta);
	else
		ray->deltadist.y = ray->coef.y;
}

//for vertical RC
void	set_ray_coef_vt(t_ray *ray)
{
	ray->coef.y = -1;
	ray->coef.x = 1;
	if (ray->player.dir_field == N_W)
		ray->coef.x = -1;
	else if (ray->player.dir_field == S_W)
	{
		ray->coef.x = -1;
		ray->coef.y = 1;
	}
	else if (ray->player.dir_field == S_E)
		ray->coef.y = 1;
	else if (ray->player.dir_field == W)
		ray->coef.y = 0;
	else if (ray->player.dir_field == S)
		ray->coef.y = 1;
	else if (ray->player.dir_field == E)
		ray->coef.y = 0;
}
