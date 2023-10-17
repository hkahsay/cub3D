/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:18:34 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/17 11:18:43 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_time(t_time *time)
{
	time->time = 0;
	time->oldTime = 0;
}

// void calculate_step_sideDist(t_ray *ray)
// {
// 	if (ray->rayDir.x < 0)
// 	{
// 		ray->step.x = -1;
// 		ray->sideDist.x = (ray->player->pos.x - ray->tileSize.x) * ray->deltaDist.x;
// 	}
// 	else
// 	{
// 		ray->step.x = 1;
// 		ray->sideDist.x = (ray->tileSize.x + 1.0f - ray->player->pos.x) *ray->deltaDist.x;
// 	}
// 	if (ray->rayDir.y < 0)
// 	{
// 		ray->step.y = -1;
// 		ray->sideDist.y = (ray->player->pos.y - ray->tileSize.y) * ray->deltaDist.y;
// 	}
// 	else
// 	{
// 		ray->step.y = 1;
// 		ray->sideDist.y = (ray->tileSize.y + 1.0f - ray->player->pos.y) * ray->deltaDist.y;
// 	}
// }
