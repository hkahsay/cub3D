/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:36:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/11 13:52:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_direction(t_player *player)
{
	if (player->dir > 0 && player->dir < M_PI)
	{
		if (player->dir == M_PI / 2)
			player->dir_field = N;
		else if (player->dir > M_PI / 2 && player->dir < M_PI)
			player->dir_field = N_W;
		else
			player->dir_field = N_E;
	}
	else if (player->dir > M_PI && player->dir < 2 * M_PI)
	{
		if (player->dir == 3 * M_PI / 2)
			player->dir_field = S;
		else if (player->dir > M_PI && player->dir < 3 * M_PI / 2)
			player->dir_field = S_W;
		else
			player->dir_field = S_E;
	}
	else if (player->dir == M_PI)
		player->dir_field = W;
	else if (player->dir == 0 && player->dir == 2 * M_PI)
		player->dir_field = E;
}

//forward = dir = 1, backward = dir = -1
void	move_straight(t_coord *update, t_game *game, int dir)
{
	if (dir != 1 && dir != -1)
		return ;
	if (dir == forward)
	{
		if (game->player.dir_field == N || game->player.dir_field == W)
			straight_dir(update, game, 1);
		else
			straight_dir(update, game, 0);
	}
	else if (dir == backward)
		{
		if (game->player.dir_field == N || game->player.dir_field == W)
			straight_dir(update, game, 0);
		else
			straight_dir(update, game, 1);
	}
}

/*
north or west & forward: flag = 1
north or west & backward: flag = 0
south or east & forward: flag = 1
south or east & backward: flag = 0
*/
void	straight_dir(t_coord *update, t_game *game, int flag)
{
	if ((game->player.dir_field == N || game->player.dir_field == S) && flag)
	{
		update->y = game->player.pos.y - 0.2;
		update->x = game->player.pos.x;
	}
	if ((game->player.dir_field == W || game->player.dir_field == E) && flag)
	{
		update->y = game->player.pos.y;
		update->x = game->player.pos.x - 0.2;
	}
	if ((game->player.dir_field == S || game->player.dir_field == N) && !flag)
	{
		update->y = game->player.pos.y + 0.2;
		update->x = game->player.pos.x;
	}
	if ((game->player.dir_field == E || game->player.dir_field == W) && !flag)
	{
		update->y = game->player.pos.y;
		update->x = game->player.pos.x + 0.2;
	}
}

/*
for north angle & forward motion: flag == 1
for north angle & backward motion: flag == 0
for south angle & forward motion: flag == 0
for south angle & backward motion: flag == 1

dir: already the beta angle depending on direction for sin/cos
*/
void	move_in_angle(t_coord *update, t_player *player, int flag, double dir)
{
	if ((player->dir_field == N_E || player->dir_field == S_W) && flag)
	{
		update->x = player->pos.x + sin(dir) * 0.2;
		update->y = player->pos.y - cos(dir) * 0.2;
	}
	else if ((player->dir_field == N_W || player->dir_field == S_E) && flag)
	{
		update->x = player->pos.x - cos(dir) * 0.2;
		update->y = player->pos.y - sin(dir) * 0.2;
	}
	else if ((player->dir_field == N_E || player->dir_field == S_W) && !flag)
	{
		update->x = player->pos.x - sin(dir) * 0.2;
		update->y = player->pos.y + cos(dir) * 0.2;
	}
	else if ((player->dir_field == N_W || player->dir_field == S_E) && !flag)
	{
		update->x = player->pos.x + cos(dir) * 0.2;
		update->y = player->pos.y + sin(dir) * 0.2;
	}
}
