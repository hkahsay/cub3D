/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:55:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 17:31:56 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//degree to radian
double	angle_to_rad(double rad)
{
	rad *= (M_PI / 180);
	return (rad);
}

//radian to degree
double	rad_to_angle(double angle)
{
	angle = angle * (180 / M_PI);
	return (angle);
}

/*check_north is returns 1 if the angle is between 0 and 180 degrees
that is the player is facing north
else it returns 0 thats is the player is facing south*/
int	check_north(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (1);
	else
		return (0);
}

/*check_west is returns 1 if the angle is between 90 and 270 degrees
that is the player is facing west
else it returns 0 thats is the player is facing east*/
int	check_west(double angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (1);
	else
		return (0);
}

//normalize angle when < 0 or > 2 * M_PI
void	normalize_angle_rad(double *angle)
{
	*angle = remainder(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}
