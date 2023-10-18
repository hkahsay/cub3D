/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:56:37 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/18 11:53:27 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	normalize_angle_rad(double *angle)
{
	*angle = remainder(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}
