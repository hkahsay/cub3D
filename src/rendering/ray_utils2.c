/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:44:49 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/25 10:55:18 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	check_map_error_movement(double x, double y, t_game *game)
{
	t_map	map_data;

	map_data = game->data->map_data;
	if ((int)x < 0 || (int)x >= map_data.m_width || \
		(int)y < 0 || (int)y >= map_data.m_height)
		return (2);
	else if (map_data.map[(int)y] \
	[(int)x] != '0')
		return (1);
	else if (map_data.map[(int)(y + 0.1)] \
	[(int)x] != '0')
		return (1);
	else if (map_data.map[(int)(y + 0.1)] \
	[(int)(x + 0.1)] != '0')
		return (1);
	else if (map_data.map[(int)y] \
	[(int)(x + 0.1)] != '0')
		return (1);
	return (0);
}