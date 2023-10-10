/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:55:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/10 14:43:04 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	angle_to_rad(double rad)
{
	rad *= (M_PI / 180);
	return (rad);
}

double	rad_to_angle(double angle)
{
	angle = angle * (180 / M_PI);
	return (angle);
}

int	pixel_to_coord(float n)
{
	int	res;

	res = n / SCALE_MINI_MAP;
	return (res);
}

//check_north is returns 1 if the angle is between 0 and 180 degrees
//that is the player is facing north
//else it returns 0 thats is the player is facing south
int	check_north(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (1);
	else
		return (0);
}

//check_west is returns 1 if the angle is between 90 and 270 degrees
//that is the player is facing west
//else it returns 0 thats is the player is facing east

int	check_west(double angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (1);
	else
		return (0);
}
