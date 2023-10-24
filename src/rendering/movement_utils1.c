/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:36:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 18:28:41 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
side = 1 = LEFT, side = 0 = RIGHT
adjust the dir_field but not the dir itself for right/left turns
*/
void	left_right_adjust(t_player *player, int side)
{
	if (side == LEFT)
	{
		if (player->dir_field == N)
			player->dir_field = W;
		else if (player->dir_field == N_E)
			player->dir_field = N_W;
		else
			player->dir_field -= 1;
	}
	else
	{
		if (player->dir_field == W)
			player->dir_field = N;
		else if (player->dir_field == N_W)
			player->dir_field = N_E;
		else
			player->dir_field += 1;
	}
}

//calculate angle opposite of viewing angle in 90 degrees
void	beta_angle_calc(t_player *player)
{
	if (player->dir_field == N_E)
		player->beta = (M_PI / 2) - player->dir;
	else if (player->dir_field == N_W)
		player->beta = M_PI - player->dir;
	else if (player->dir_field == S_W)
		player->beta = (3 * M_PI / 2) - player->dir;
	else if (player->dir_field == S_E)
		player->beta = (2 * M_PI) - player->dir;
}
