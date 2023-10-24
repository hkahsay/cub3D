/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:36:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/24 17:58:23 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//check player direction(N, E, S, W) or in between (N_E, S_E, S_W, N_W)
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
	else if (player->dir == 0 || player->dir == 2 * M_PI)
		player->dir_field = E;
}

// FORWARD = dir = 1, BACKWARD = dir = -1
void	move_straight(t_coord *update, t_game *game, int dir)
{
	if (dir != 1 && dir != -1)
		return ;
	if (dir == FORWARD)
	{
		if (game->player.dir_field == N || game->player.dir_field == W)
			straight_dir(update, game, 1);
		else
			straight_dir(update, game, 0);
	}
	else if (dir == BACKWARD)
	{
		if (game->player.dir_field == N || game->player.dir_field == W)
			straight_dir(update, game, 0);
		else
			straight_dir(update, game, 1);
	}
}

/*
north or west & FORWARD: flag = 1
north or west & BACKWARD: flag = 0
south or east & FORWARD: flag = 0
south or east & BACKWARD: flag = 1
*/
void	straight_dir(t_coord *update, t_game *game, int flag)
{
	if ((game->player.dir_field == N || game->player.dir_field == S) && flag)
	{
		update->y = game->player.pos.y - 0.1;
		update->x = game->player.pos.x;
	}
	if ((game->player.dir_field == W || game->player.dir_field == E) && flag)
	{
		update->y = game->player.pos.y;
		update->x = game->player.pos.x - 0.1;
	}
	if ((game->player.dir_field == S || game->player.dir_field == N) && !flag)
	{
		update->y = game->player.pos.y + 0.1;
		update->x = game->player.pos.x;
	}
	if ((game->player.dir_field == E || game->player.dir_field == W) && !flag)
	{
		update->y = game->player.pos.y;
		update->x = game->player.pos.x + 0.1;
	}
}

/*
for north angle & FORWARD motion: flag == 1
for north angle & BACKWARD motion: flag == 0
for south angle & FORWARD motion: flag == 0
for south angle & BACKWARD motion: flag == 1
dir: already the beta angle depending on direction for sin/cos
*/
void	move_in_angle(t_coord *update, t_player *player, int flag)
{
	if ((player->dir_field == N_E || player->dir_field == S_W) && flag)
	{
		update->x = player->pos.x + sin(player->beta) * 0.1;
		update->y = player->pos.y - cos(player->beta) * 0.1;
	}
	else if ((player->dir_field == N_W || player->dir_field == S_E) && flag)
	{
		update->x = player->pos.x - cos(player->beta) * 0.1;
		update->y = player->pos.y - sin(player->beta) * 0.1;
	}
	else if ((player->dir_field == N_E || player->dir_field == S_W) && !flag)
	{
		update->x = player->pos.x - sin(player->beta) * 0.1;
		update->y = player->pos.y + cos(player->beta) * 0.1;
	}
	else if ((player->dir_field == N_W || player->dir_field == S_E) && !flag)
	{
		update->x = player->pos.x + cos(player->beta) * 0.1;
		update->y = player->pos.y + sin(player->beta) * 0.1;
	}
}

/*
	NW or NE and left: flag = 1
	SE or SW and left: flag = 0
	NW or NE and right: flag = 0
	SE or SW and right: flag = 1
*/
void	move_angle_left_right(t_coord *update, t_player *player, int flag)
{
	if ((player->dir_field == N_W || player->dir_field == S_E) && flag)
	{
		update->x = player->pos.x - sin(player->beta) * 0.1;
		update->y = player->pos.y + cos(player->beta) * 0.1;
	}
	else if ((player->dir_field == N_E || player->dir_field == S_W) && flag)
	{
		update->x = player->pos.x - cos(player->beta) * 0.1;
		update->y = player->pos.y - sin(player->beta) * 0.1;
	}
	else if ((player->dir_field == S_E || player->dir_field == N_W) && !flag)
	{
		update->x = player->pos.x + sin(player->beta) * 0.1;
		update->y = player->pos.y - cos(player->beta) * 0.1;
	}
	else if ((player->dir_field == S_W || player->dir_field == N_E) && !flag)
	{
		update->x = player->pos.x + cos(player->beta) * 0.1;
		update->y = player->pos.y + sin(player->beta) * 0.1;
	}
}
