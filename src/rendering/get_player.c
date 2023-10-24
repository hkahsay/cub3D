/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:57:44 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 19:48:58 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*get player coordinates from map coordinates
get the right direction + beta angle instead of alpha direction angle
for movement calculations*/
void	get_player(t_player *player, t_map *map_data)
{
	player->pos.x = map_data->play_pos.col + 0.5;
	player->pos.y = map_data->play_pos.row + 0.5;
	player->dir = angle_to_rad(map_data->play_pos.dir);
	check_direction(player);
	beta_angle_calc(player);
}
