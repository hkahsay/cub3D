/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:42:03 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/17 18:30:33 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	//get euclid distance
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
