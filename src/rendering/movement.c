/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:56:58 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/11 18:09:59 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	move_forward(t_game *game)
{
	t_coord	update;

	check_direction(&(game->player));
	beta_angle_calc(&game->player);
	if (game->player.dir_field == N_E)
		move_in_angle(&update, &(game->player), 1, game->player.beta);		//try with beta angle
	else if (game->player.dir_field == N_W)
		move_in_angle(&update, &(game->player), 1, \
		M_PI - game->player.dir);
	else if (game->player.dir_field == S_W)
		move_in_angle(&update, &(game->player), 0, \
		(3 * M_PI / 2) - game->player.dir);
	else if (game->player.dir_field == S_E)
		move_in_angle(&update, &(game->player), 0, \
		(2 * M_PI) - game->player.dir);
	else
		move_straight(&update, game, FORWARD);
	if (game->data->map_data.map[(int)update.y] \
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_backward(t_game *game)
{
	t_coord	update;

	check_direction(&(game->player));
	if (game->player.dir_field == N_E)
		move_in_angle(&update, &(game->player), 0, \
		(M_PI / 2) - game->player.dir);
	else if (game->player.dir_field == N_W)
		move_in_angle(&update, &(game->player), 0, \
		M_PI - game->player.dir);
	else if (game->player.dir_field == S_W)
		move_in_angle(&update, &(game->player), 1, \
		(3 * M_PI / 2) - game->player.dir);
	else if (game->player.dir_field == S_E)
		move_in_angle(&update, &(game->player), 1, \
		(2 * M_PI) - game->player.dir);
	else
		move_straight(&update, game, BACKWARD);
	if (game->data->map_data.map[(int)update.y] \
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_left(t_game *game)
{
	t_coord	update;

	check_direction(&(game->player));
	left_right_adjust(&(game->player), LEFT);
	if (game->player.dir_field == N_E)
		move_in_angle(&update, &(game->player), 1, \
		(M_PI / 2) - (game->player.dir + M_PI / 2));
	else if (game->player.dir_field == N_W)
		move_in_angle(&update, &(game->player), 1, \
		M_PI - (game->player.dir + M_PI / 2));
	else if (game->player.dir_field == S_W)
		move_in_angle(&update, &(game->player), 0, \
		(3 * M_PI / 2) - (game->player.dir + M_PI / 2));
	else if (game->player.dir_field == S_E)
		move_in_angle(&update, &(game->player), 0, \
		(2 * M_PI) - (game->player.dir + M_PI / 2));
	else
		move_straight(&update, game, FORWARD);
	if (game->data->map_data.map[(int)update.y] \
	[(int)(update.x)] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}

void	move_right(t_game *game)
{
	t_coord	update;

	check_direction(&(game->player));
	left_right_adjust(&(game->player), RIGHT);
	if (game->player.dir_field == N_E)
		move_in_angle(&update, &(game->player), 1, \
		(M_PI / 2) - (game->player.dir - M_PI / 2));
	else if (game->player.dir_field == N_W)
		move_in_angle(&update, &(game->player), 1, \
		M_PI - (game->player.dir - M_PI / 2));
	else if (game->player.dir_field == S_W)
		move_in_angle(&update, &(game->player), 0, \
		(3 * M_PI / 2) - (game->player.dir - M_PI / 2));
	else if (game->player.dir_field == S_E)
		move_in_angle(&update, &(game->player), 0, \
		(2 * M_PI) - (game->player.dir - M_PI / 2));
	else
		move_straight(&update, game, FORWARD);
	if (game->data->map_data.map[(int)update.y] \
	[(int)update.x] == '0')
	{
		game->player.pos.x = update.x;
		game->player.pos.y = update.y;
	}
}
