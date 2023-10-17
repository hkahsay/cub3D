/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:56:37 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/17 17:44:10 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	normalize_angle_rad(double *angle)
{
	*angle = remainder(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
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
